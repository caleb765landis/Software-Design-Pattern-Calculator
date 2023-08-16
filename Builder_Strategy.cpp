// Builder_Strategy.cpp

#include "Builder_Strategy.h"

Builder_Strategy::Builder_Strategy()
    : result_(0)
{
    std::cout << "Created Builder_Strategy" << std::endl;
}

void Builder_Strategy::solve(std::string expression)
{
    std::cout << expression << std::endl;
}

int Builder_Strategy::result()
{
    return this->result_;
}