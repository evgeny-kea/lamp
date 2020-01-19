#include "color.h"
#include "../lamp.h"

#define KEY_ 0x20

Color::Color ()
{
}

bool Color::check_length (const Length& len) const
{
    return len == 3;
}

void Color::exec (Lamp* lamp)
{
    const Data& d = data ();
    lamp->set_color (QColor (static_cast<int> (d[0]) & 0xff, static_cast<int> (d[1]) & 0xff, static_cast<int> (d[2]) &0xff));
}

namespace
{
    Command::Ptr Create ()
    {
        return Command::Ptr (new Color ());
    }

    const bool registered = Command::Factory::Instance ().Register (KEY_, &Create);
}
