// Mult_Command.cpp

#include "Mult_Command.h"

Mult_Command::Mult_Command(Stack<int> &s) : s_(s) {}

void Mult_Command::execute()
{
    int n2 = s_.top();
    s_.pop();

    int n1 = s_.top();
    s_.pop();

    s_.push(n1 * n2);
}

bool Mult_Command::isHigherPrecedence(std::string op)
{
    if (op == "+" || op == "-")
    {
        return true;
    }
    
    return false;
}