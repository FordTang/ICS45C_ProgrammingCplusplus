#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class CursorEnd : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        previous = editor.cursorColumn();
        editor.end();
    }

    virtual void undo(Editor& editor)
    {
        editor.moveColumn(previous);
    }

private:
    int previous;
};

#endif
