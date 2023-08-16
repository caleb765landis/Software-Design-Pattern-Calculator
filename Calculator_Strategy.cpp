// Calculator_Strategy.cpp

#include "Calculator_Strategy.h"

Calculator_Strategy::Calculator_Strategy()
    :result_(0) 
{
    std::cout << "Created Calculator_Strategy" << std::endl;
}

void Calculator_Strategy::solve(std::string expression)
{
    std::cout << expression << std::endl;
}

int Calculator_Strategy::result()
{
    return this->result_;
}