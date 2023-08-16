//==============================================================================
/**
 * @file       Calculator.h
 *
 * Calculator that implements different strategies for 
 * parsing and soliving a simple mathematical expression.
 */
//==============================================================================

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include <string>
#include <sstream>

#include "Calculator_Strategy.h"
// #include "Stack.h"
// #include "Array.h"
// #include "Stack_Expr_Command_Factory.h"
// #include "Expr_Command.h"

class Calculator
{
public:
    /**
     * @brief Construct a new Calculator object
     *        defaults to factory strategy
     */
    Calculator();

    /**
     * @brief Construct a new Calculator object
     *
     * @param strategy must be either "factory" or "builder"
     *
     * @exception defaults to factory strategy if exception is caught
     */
    Calculator(std::string strategy);

    /**
     * @brief Starts Calculator main loop
     *        Gets expression input from user and passes it to chosen strategy for evaluation
     *        Outputs result from strategy
     * 
     *        Enter "QUIT" to exit main loop
     * 
     */
    void start();

    /**
     * @brief sets strategy_ of type Calculator_Strategy
     *
     * @param strategy must be either "factory" or "builder"
     *
     * @exception throws error string if strategy is invalid
     *            catch with const char *exp
     */
    void setStrategy(std::string strategy);

private:
    Calculator_Strategy strategy_;
};

#endif