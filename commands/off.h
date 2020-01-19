#ifndef OFF_H
#define OFF_H

#include "../command.h"

class Off : public Command
{
public:
    Off ();
    bool check_length (const Length&) const;
    void exec (Lamp*);
};

#endif // OFF_H
