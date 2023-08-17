// Sub_Command.cpp

#include "Sub_Command.h"

Sub_Command::Sub_Command(Stack<int> &s) : s_(s) {}

void Sub_Command::execute()
{
    int n2 = s_.top();
    s_.pop();

    int n1 = s_.top();
    s_.pop();

    s_.push(n1 - n2);
}

// returns true only if top of command stack is a number
bool Sub_Command::isHigherPrecedence(std::string op)
{
    for (char const &ch : op)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    
    return false;
}