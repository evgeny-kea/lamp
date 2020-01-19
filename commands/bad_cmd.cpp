#include "bad_cmd.h"

bool BadCmd::check_length (const Length&) const
{
    return false;
}
void BadCmd::exec (Lamp*)
{
}
