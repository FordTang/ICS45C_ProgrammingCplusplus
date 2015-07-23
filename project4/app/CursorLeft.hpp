#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"

class CursorLeft : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        editor.moveColumn(editor.cursorColumn() - 1);
    }

    virtual void undo(Editor& editor)
    {
        editor.moveColumn(editor.cursorColumn() + 1);
    }
};

#endif
