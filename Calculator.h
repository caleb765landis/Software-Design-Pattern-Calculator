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

class Calculator_Strategy;
#include "./factory_strategy/Abstract_Factory_Strategy.h"
#include "./builder_strategy/Builder_Strategy.h"

class Calculator
{
public:
    /**
     * @brief Construct a new Calculator object.
     *        Defaults to factory strategy.
     */
    Calculator();

    /**
     * @brief Construct a new Calculator object.
     *
     * @param strategy Must be either "factory" or "builder".
     *
     * @exception Defaults to factory strategy if exception is caught.
     */
    Calculator(std::string strategy);

    /**
     * @brief Destroy the Calculator object.
     * 
     */
    ~Calculator();

    /**
     * @brief Starts Calculator main loop.
     *        Gets expression input from user and passes it to chosen strategy for evaluation.
     *        Outputs result from strategy.
     * 
     *        Enter "QUIT" to exit main loop.
     * 
     */
    void start();

    /**
     * @brief Sets strategy_ of type Calculator_Strategy.
     *
     * @param strategy Must be either "factory" or "builder".
     *
     * @exception Throws error string if strategy is invalid.
     *            Catch with const char *exp.
     */
    void setStrategy(std::string strategy);

private:
    Calculator_Strategy* strategy_; // the chosen concrete strategy instance
};

#endif