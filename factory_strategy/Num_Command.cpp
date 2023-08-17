// Num_Command.cpp

#include "Num_Command.h"

Num_Command::Num_Command(Stack<int> &s, int n) : s_(s), n_(n) {}

void Num_Command::execute()
{
    s_.push(this->n_);
}

bool Num_Command::isHigherPrecedence(std::string op)
{
    return false;
}