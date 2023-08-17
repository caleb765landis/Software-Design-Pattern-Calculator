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
    /**
     * @brief solves simple math expression and stores in result_
     * 
     * @param expression 
     */
    virtual void solve(std::string expression) = 0;

    /**
     * @brief returns result_
     * 
     * @return int 
     */
    virtual int result() = 0;

};

#endif