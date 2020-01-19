#ifndef BAD_CMD_H
#define BAD_CMD_H

#include "../command.h"

class BadCmd : public Command
{
public:
    bool check_length (const Length&) const;
    void exec (Lamp* lamp);
};

#endif // BAD_CMD_H
