#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP

#include "Command.hpp"

class CursorHome : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        previous = editor.cursorColumn();
        editor.home();
    }

    virtual void undo(Editor& editor)
    {
        editor.moveColumn(previous);
    }

private:
    int previous;
};

#endif
