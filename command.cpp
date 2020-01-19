#include "command.h"
#include "commands/bad_cmd.h"

#include <QMessageBox>

Command::~Command ()
{
}

bool Command::CommandFactory::Register (const Command::Type& key, CreateFunction creator)
{
    Reester::iterator pos = commands_.find (key);
    if (pos != commands_.end ())
    {
        qDebug ("Duplicate command number");
        QCoreApplication::exit (EXIT_FAILURE);
    }
    commands_.insert (key, creator);
    return true;
}

Command::Ptr Command::CommandFactory::Create (const Command::Type& key)
{
    Reester::iterator pos = commands_.find (key);
    if (pos == commands_.end ())
    {
        return Command::Ptr (new BadCmd ());
    }
    else
    {
        Command::Ptr ptr = pos.value () ();
        ptr->type_ = key;
        return ptr;
    }
}
