#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

class DeleteLine : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        position = editor.cursorColumn(); 
        deleted = editor.line(editor.cursorLine());
        editor.safeDeleteLine();
    }

    virtual void undo(Editor& editor)
    {
        if (editor.cursorLine() != 1 || editor.line(1) != "")
        {
            editor.end();
            editor.newLine();
        }
        editor.insertLine(deleted);
        editor.moveColumn(position);
    }
private:
    int position;
    std::string deleted;
};

#endif
