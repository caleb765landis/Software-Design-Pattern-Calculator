// Abstract_Factory_Strategy.cpp

#include "Abstract_Factory_Strategy.h"

Abstract_Factory_Strategy::Abstract_Factory_Strategy()
    : result_(0)
{
    std::cout << "Created Abstract_Factory_Strategy" << std::endl;
}

void Abstract_Factory_Strategy::solve(std::string expression)
{
    std::cout << expression << std::endl;
}

int Abstract_Factory_Strategy::result()
{
    return this->result_;
}