#ifndef COMMAND_H
#define COMMAND_H

#include <QMap>
#include <QVector>
#include <QtCore>
#include <QtGlobal>

#include "singleton.h"

class Lamp;

class Command
{
public:
    typedef QSharedPointer<Command> Ptr;
    typedef quint8 Type;
    typedef quint16 Length;
    typedef QVector<char> Data;

public:
    virtual ~Command ();
    virtual void exec (Lamp* lamp) = 0;

    virtual Type type () const { return type_; }
    virtual const Data& data () const { return data_; }
    virtual void data (const Data& data) { data_ = data; }
    virtual bool check_length (const Length&) const = 0;

private:
    class CommandFactory
    {
    public:
        typedef Ptr (*CreateFunction) ();

    private:
        typedef QMap<Type, CreateFunction> Reester;

    public:
        bool Register (const Type& key, CreateFunction creator);
        Ptr Create (const Type& key);

    private:
        Reester commands_;
    };
    friend class CommandFactory;

public:
    typedef Singleton<CommandFactory> Factory;

private:
    Type type_;
    Data data_;
};

#endif // COMMAND_H
