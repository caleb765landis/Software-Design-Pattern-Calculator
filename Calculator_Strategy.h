//==============================================================================
/**
 * @file       Calculator_Strategy.h
 *
 * Abstract parent class for different strategies to parse and solve
 * simple mathematical expressions/
 */
//==============================================================================

#ifndef _CALCULATOR_STRATEGY_H_
#define _CALCULATOR_STRATEGY_H_

#include <iostream>
#include <string>
#include <sstream>

// #include "Stack.h"
// #include "Array.h"
// #include "Stack_Expr_Command_Factory.h"
// #include "Expr_Command.h"

class Calculator_Strategy
{
public:
    Calculator_Strategy();

    void solve(std::string expression);

    int result();

    private:
        int result_;
};

#endif