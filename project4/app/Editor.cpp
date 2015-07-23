// Editor.cpp
//
// ICS 45C Fall 2014
// Project #4: People Just Love to Play with Words
//
// Implementation of the Editor class

#include "Editor.hpp"
#include "EditorException.hpp"
#include "BooEditLog.hpp"

Editor::Editor()
{
    cLine = 1;
    cColumn = 1;
    data.push_back("");
}


int Editor::cursorLine() const
{
    return cLine;
}


int Editor::cursorColumn() const
{
    return cColumn;
}


int Editor::lineCount() const
{
    return data.size();
}


const std::string& Editor::line(int lineNumber) const
{
    return data.at(lineNumber - 1);
}


void Editor::moveLine(int newLine)
{
    if (newLine < 1)
        throw EditorException("Top of File");
    else if (newLine > this->lineCount())
        throw EditorException("Bottom of File");
    cLine = newLine;
    if (cColumn > this->line(cLine).size() + 1)
        cColumn = this->line(cLine).size() + 1;
}


void Editor::moveColumn(int newColumn)
{
    if (newColumn < 1)
    {
        if (cLine == 1)
            throw EditorException("Top of File");
        cLine--;
        cColumn = this->line(cLine).size() + 1;
    }
    else if (newColumn > this->line(cLine).size() + 1)
    {
        if (cLine + 1 > this->lineCount())
            throw EditorException("End of File");
        cLine++;
        cColumn = 1;
    }
    else
        cColumn = newColumn;
}


void Editor::insertChar(const char* C)
{
    data.at(cLine - 1).insert(cColumn - 1, C);
    cColumn++;
}


char Editor::backSpace()
{
    if (cLine == 1 && cColumn == 1)
        throw EditorException("Top of File");

    else if (cColumn != 1)
    {   
        char deleted = data.at(cLine - 1)[cColumn - 2];
        data.at(cLine - 1).erase(cColumn - 2, 1);
        this->moveColumn(cColumn - 1);
        return deleted;
    }

    else
    {
        this->moveLine(cLine - 1);
        this->end();
        data.at(cLine - 1) += data.at(cLine);
        data.erase(data.begin() + cLine);
        return '\0';
    }
}

void Editor::home()
{
    cColumn = 1;
}

void Editor::end()
{
    cColumn = this->line(cLine).size() + 1;
}

void Editor::newLine()
{
    data.insert(data.begin() + cLine, ""); 
    if (cColumn - 1 < this->line(cLine).size())
    {
        data.at(cLine) = data.at(cLine - 1).substr(cColumn - 1);
        data.at(cLine - 1) = data.at(cLine - 1).erase(cColumn - 1, data.at(cLine - 1).size());
    }
    this->moveLine(cLine + 1);
    this->home();
}

void Editor::deleteLine()
{
    data.erase(data.begin() + cLine - 1);
}

void Editor::safeDeleteLine()
{
    if (this->lineCount() == 1 && this->line(1) == "")
        throw EditorException("Already Empty");
    this->deleteLine();
    if (this->lineCount() == 0)
        data.push_back("");
    if (cLine > this->lineCount())
        this->moveLine(cLine - 1);
    if (cColumn > this->line(cLine).size())
        this->end();
}

void Editor::insertLine(const std::string& iLine)
{
    data.at(cLine - 1) += iLine;
}
