// Mod_Command.cpp

#include "Mod_Command.h"

Mod_Command::Mod_Command(Stack<int> &s) : s_(s) {}

void Mod_Command::execute()
{
    int n2 = s_.top();
    s_.pop();

    int n1 = s_.top();
    s_.pop();

    s_.push(n1 % n2);
}

bool Mod_Command::isHigherPrecedence(std::string op)
{
    if (op == "+" || op == "-")
    {
        return true;
    }
    
    return false;
}