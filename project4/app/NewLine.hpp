#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"

class NewLine : public Command
{
public:
    virtual void execute(Editor& editor)
    {
        cursor = editor.cursorColumn();
        editor.newLine();
    }

    virtual void undo(Editor& editor)
    {
        int currentLine = editor.cursorLine();
        editor.moveLine(--currentLine);
        editor.insertLine(editor.line(++currentLine));
        editor.moveLine(currentLine);
        editor.deleteLine();
        editor.moveLine(--currentLine);
        editor.moveColumn(cursor);
    }
private:
    int cursor;
};

#endif
