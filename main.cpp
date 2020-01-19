#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QString>
#include <QStringList>

#include "lamp.h"

int main (int argc, char *argv[])
{
    QApplication a (argc, argv);

    QCommandLineParser parser;
    QCommandLineOption addressOpt (QStringList () << "address" << "a", "Host IP address", "address", "127.0.0.1");
    QCommandLineOption portOpt (QStringList () << "port" << "p", "Host port number", "port", "9999");
    parser.addOption (addressOpt);
    parser.addOption (portOpt);

    parser.process (a);

    const QStringList args = parser.optionNames();

    QString address = parser.value (addressOpt);
    QString port = parser.value (portOpt);

    Channel channel (address, static_cast<quint16> (port.toUInt ()));

    Lamp l (&channel);
    l.show ();

    return a.exec ();
}
