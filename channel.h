#ifndef CHANNEL_H
#define CHANNEL_H

#include <QtCore>
#include <QtNetwork>

#include "command.h"

class Channel : public QObject
{    
    Q_OBJECT

public:
    Channel (const QString& host, quint16 port);
    ~Channel ();

private slots:
    void read_cmd ();
    void process_error (QAbstractSocket::SocketError socketError);
    void reconnect ();

signals:
    void new_cmd (Command*);

private:
    QString host_;
    quint16 port_;
    QSharedPointer<QTcpSocket> tcpSocket_;
    QDataStream in_;
    Command::Ptr cmd_;
};

#endif // CHANNEL_H
