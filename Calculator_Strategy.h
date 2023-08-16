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

class Calculator_Strategy
{
public:
    virtual void solve(std::string expression) = 0;

    virtual int result() = 0;

    protected:
        int result_;
};

#endif