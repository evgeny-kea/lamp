#include "channel.h"

Channel::Channel (const QString& host, quint16 port)
    : host_ (host), port_ (port)
{
    in_.setByteOrder (QDataStream::BigEndian);
    tcpSocket_ = QSharedPointer<QTcpSocket> (new QTcpSocket ());
    in_.setDevice (tcpSocket_.get ());

    connect (tcpSocket_.get (), SIGNAL (disconnected ()), SLOT (reconnect ()));
    connect (tcpSocket_.get (), SIGNAL (readyRead ()), SLOT (read_cmd ()));
    connect (tcpSocket_.get (), SIGNAL (error (QAbstractSocket::SocketError)), SLOT (process_error (QAbstractSocket::SocketError)));

    tcpSocket_->connectToHost (host, port);
}

Channel::~Channel ()
{
    tcpSocket_->disconnectFromHost (); // but it unnecessary because QTcpSocket destructor calls 'close' method itself
}

void Channel::read_cmd ()
{
    in_.startTransaction ();

    Command::Type type;
    Command::Length len;
    in_ >> type >> len;
    cmd_ = Command::Factory::Instance ().Create (type);
    if (cmd_->check_length (len) == false)
    {
        in_.skipRawData (static_cast<int> (tcpSocket_->bytesAvailable ()));
        in_.abortTransaction ();
        return;
    }
    if (len > 0)
    {
        Command::Data data (len);
        if (len != in_.readRawData (data.data (), len))
        {
            in_.abortTransaction ();
            return;
        }
        cmd_->data (data);
    }

    if (!in_.commitTransaction ())
        return;

    emit new_cmd (cmd_.get ());
}

void Channel::process_error (QAbstractSocket::SocketError)
{
    in_.abortTransaction ();
    tcpSocket_->abort ();
    reconnect ();
}

void Channel::reconnect ()
{
    if (tcpSocket_->state() != QAbstractSocket::ConnectingState)
    {
        tcpSocket_->connectToHost (host_, port_);
        QThread::msleep (100);
    }
}
