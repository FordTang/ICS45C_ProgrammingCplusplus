#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"

class Backspace : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        C = editor.backSpace();
    }

    virtual void undo(Editor& editor)
    {
        if (C == '\0')
        {
            editor.newLine();
        }

        else
        {
            editor.insertChar(&C);
        }
    }

private:
    char C;
};

#endif
