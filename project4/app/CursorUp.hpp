#ifndef CURSORUP_HPP
#define CURSORUP_HPP

#include "Command.hpp"

class CursorUp : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        column = editor.cursorColumn();
        editor.moveLine(editor.cursorLine() - 1);
    }

    virtual void undo(Editor& editor)
    {
        editor.moveLine(editor.cursorLine() + 1);
        editor.moveColumn(column);
    }

private:
    int column;
};

#endif
