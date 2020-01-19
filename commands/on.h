#ifndef ON_H
#define ON_H

#include "../command.h"

class On : public Command
{
public:
    On ();
    bool check_length (const Length&) const;
    void exec (Lamp*);
};

#endif // ON_H
