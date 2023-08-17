// Div_Command.cpp

#include "Div_Command.h"

Div_Command::Div_Command(Stack<int> &s) : s_(s) {}

void Div_Command::execute()
{
    int n2 = s_.top();
    s_.pop();

    int n1 = s_.top();
    s_.pop();

    s_.push(n1 / n2);
}

bool Div_Command::isHigherPrecedence(std::string op)
{
    if (op == "+" || op == "-")
    {
        return true;
    }
    
    return false;
}