#include "on.h"
#include "../lamp.h"

#define KEY_ 0x12

On::On ()
{
}

bool On::check_length (const Length& len) const
{
    return len == 0;
}

void On::exec (Lamp* lamp)
{
    lamp->set_enabled (true);
}

namespace
{
    Command::Ptr Create ()
    {
        return Command::Ptr (new On ());
    }

    const bool registered = Command::Factory::Instance ().Register (KEY_, &Create);
}
