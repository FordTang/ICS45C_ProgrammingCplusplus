#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"

class InsertChar : public Command
{
public:
    InsertChar(char C) : C{C}
    {
    }
    
    virtual void execute(Editor& editor)
    {
        editor.insertChar(&C);
    }

    virtual void undo(Editor& editor)
    {
        editor.backSpace();
    }
private:
    char C;
};

#endif
