// CommandProcessor.cpp
//
// ICS 45C Fall 2014
// Project #4: People Just Love to Play with Words
//
// Implementation of the CommandProcessor class

#include <stack>
#include <algorithm>
#include "CommandProcessor.hpp"
#include "EditorException.hpp"
#include "Keypress.hpp"
#include "InsertChar.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "CursorLeft.hpp"
#include "CursorRight.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "NewLine.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"

CommandProcessor::CommandProcessor(Editor& editor, EditorView& view)
    : editor{editor}, view{view}
{
}


namespace
{
    // An "enum class" defines a type that has one of the constant values
    // specified.  So, in this case, a variable of type UserInteractionType
    // could have the value UserInteractionType::command,
    // UserInteractionType::undo, etc.
    enum class UserInteractionType
    {
        command,
        undo,
        redo,
        quit
    };


    // A UserInteraction describes one interaction that the user undertakes
    // with BooEdit.  There are four different kinds of interactions:
    //
    // * Commands, which attempt to affect some kind of change on the editor
    // * Undo, which asks for the previous change to be undone
    // * Redo, which asks for the most-recently undone change to be redone
    // * Quit, which asks for the editor to be stopped altogether
    //
    // A Command* is included for the case where UserInteractionType::command
    // is the specified type; otherwise, it will be nullptr.
    struct UserInteraction
    {
        UserInteractionType type;
        Command* command;
    };


    // You'll want these three functions, but I'm commenting them out for now,
    // so that this will compile without warnings.

    UserInteraction makeCommandInteraction(Command* command)
    {
        return UserInteraction{UserInteractionType::command, command};
    }


    UserInteraction makeUndoInteraction()
    {
        return UserInteraction{UserInteractionType::undo, nullptr};
    }


    UserInteraction makeRedoInteraction()
    {
        return UserInteraction{UserInteractionType::redo, nullptr};
    }

    
    UserInteraction makeQuitInteraction()
    {
        return UserInteraction{UserInteractionType::quit, nullptr};
    }


    // You will need to update this function to watch for the right keypresses
    // and build the right kinds of user interactions.  I've added handling
    // for "quit" here, but you'll need to add the others.
    UserInteraction nextUserInteraction()
    {
        while (true)
        {
            Keypress keypress = nextKeypress();

            if (keypress.ctrl)
            {
                // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

                switch (keypress.c)
                {
                case 'X':
                    return makeQuitInteraction();
                case 'O':
                    return makeCommandInteraction(new CursorRight);
                case 'U':
                    return makeCommandInteraction(new CursorLeft);
                case 'Z':
                    return makeUndoInteraction();
                case 'A':
                    return makeRedoInteraction();
                case 'I':
                    return makeCommandInteraction(new CursorUp);
                case 'K':
                    return makeCommandInteraction(new CursorDown);
                case 'Y':
                    return makeCommandInteraction(new CursorHome);
                case 'P':
                    return makeCommandInteraction(new CursorEnd);
                case 'J':
                    return makeCommandInteraction(new NewLine);
                case 'M':
                    return makeCommandInteraction(new NewLine);
                case 'H':
                    return makeCommandInteraction(new Backspace);
                case 'D':
                    return makeCommandInteraction(new DeleteLine);
                }
            }
            else
            {
                // The user pressed a normal key (e.g., 'h') without holding
                // down Ctrl; react accordingly
                return makeCommandInteraction(new InsertChar(keypress.c));
            }
        }
    }
}


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void CommandProcessor::run()
{
    std::stack<UserInteraction> undoStack;
    std::stack<UserInteraction> redoStack;

    view.refresh();

    while (true)
    {
        UserInteraction interaction = nextUserInteraction();

        if (interaction.type == UserInteractionType::quit)
        {
            break;
        }
        else if (interaction.type == UserInteractionType::undo)
        {
            if (undoStack.empty())
            {
                view.showErrorMessage("Undo Empty");
                view.refresh();
            }
            else
            {
                UserInteraction undoInteraction = undoStack.top();
                undoStack.pop();
                redoStack.push(undoInteraction);
                undoInteraction.command->undo(editor);
                view.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type == UserInteractionType::redo)
        {
            if (redoStack.empty())
            {
                view.showErrorMessage("Redo Empty");
                view.refresh();
            }
            else
            {
                UserInteraction redoInteraction = redoStack.top();
                redoStack.pop();
                undoStack.push(redoInteraction);
                redoInteraction.command->execute(editor);
                view.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type == UserInteractionType::command)
        {
            try
            {
                interaction.command->execute(editor);
                view.clearErrorMessage();
                undoStack.push(interaction);
            }
            catch (EditorException& e)
            {
                view.showErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
        }
    }
    
    while (!undoStack.empty())
    {
        UserInteraction interaction = undoStack.top();
        delete interaction.command;
        undoStack.pop();
    }

    while (!redoStack.empty())
    {
        UserInteraction interaction = redoStack.top();
        delete interaction.command;
        redoStack.pop();
    }
}

