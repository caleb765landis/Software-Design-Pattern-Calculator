//==============================================================================
/**
 * @file       Abstract_Factory_Strategy.h
 *
 * Concrete implementation of calculator strategy that makes use of the
 * abstract factory software design pattern.
 */
//==============================================================================

#ifndef _ABSTRACT_FACTORY_STRATEGY_H_
#define _ABSTRACT_FACTORY_STRATEGY_H_

#include <iostream>
#include <string>
#include <sstream>

#include "../Calculator_Strategy.h"
#include "../utils/Stack.h"
#include "../utils/Array.h"
#include "Stack_Expr_Command_Factory.h"
#include "./expression_commands/Expr_Command.h"

class Abstract_Factory_Strategy: public Calculator_Strategy
{
public:
    /**
     * @brief Construct a new Abstract_Factory_Strategy object
     *        Initializes result_ to 0
     * 
     */
    Abstract_Factory_Strategy();

    /**
     * @brief solves simple math expression using abstract factory pattern and stores in result_
     *
     * @param expression
     */
    void solve(std::string expression);

    /**
     * @brief returns result_
     * 
     * @return int 
     */
    int result();

private:
    int result_; // result of math expression once the expression has been evaluated

    /**
     * @brief Creates expression commands while converting infix expression to postfix expression.
     *        Stores posftix expression in Expr_Command array reference called postfix.
     * 
     * @param infix reference to string containing simple math expression in infix notation
     * @param factory reference to the Expr_Command_Factory that creates Expr_Commands
     * @param postfix reference to an array of Expr_Commands organized in postfix notation
     */
    void infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix);

    /**
     * @brief Executes each command in postfix array in order of index.
     *        When each command executes, the current state of the result of the
     *        expression is stored in a stack reference given to each command.
     *
     * @param postfix reference to an array of Expr_Commands organized in postfix notation
     */
    void evaluate_postfix(Array<Expr_Command *> &postfix);

    /**
     * @brief checks if string is an operand
     * 
     * @param s 
     * @return true if string is only a number
     * @return false if string is not a number
     */
    bool isOperand(const std::string &s);

    /**
     * @brief checks if string is only an operator
     * 
     * @param s 
     * @return true if string only contains one operator
     * @return false if string contains something other than only an operator
     */
    bool isOperator(const std::string &s);
};

#endif