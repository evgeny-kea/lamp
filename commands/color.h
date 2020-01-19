#ifndef COLOR_H
#define COLOR_H

#include "../command.h"

class Color : public Command
{
public:
    Color ();
    bool check_length (const Length&) const;
    void exec (Lamp*);
};

#endif // COLOR_H
