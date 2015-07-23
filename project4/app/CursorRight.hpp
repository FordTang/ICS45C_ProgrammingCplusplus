#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"

class CursorRight : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        editor.moveColumn(editor.cursorColumn() + 1);
    }

    virtual void undo(Editor& editor)
    {
        editor.moveColumn(editor.cursorColumn() - 1);
    }
};

#endif
