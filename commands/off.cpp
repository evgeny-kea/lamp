#include "off.h"
#include "../lamp.h"

#define KEY_ 0x13

Off::Off ()
{
}

bool Off::check_length (const Length& len) const
{
    return len == 0;
}

void Off::exec (Lamp* lamp)
{
    lamp->set_enabled (false);
}

namespace
{
    Command::Ptr Create ()
    {
        return Command::Ptr (new Off ());
    }

    const bool registered = Command::Factory::Instance ().Register (KEY_, &Create);
}
