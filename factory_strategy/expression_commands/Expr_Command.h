//==============================================================================
/**
 * @file       Expr_Command.h
 *
 * Abstract parent class for expression commands.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_
#define _EXPR_COMMAND_

#include <string>
#include "../../utils/Stack.h"

class Expr_Command
{
public:
    // Pure virtual methods

    /**
     * @brief Executes the command according to corresponding operator or operand.
     * 
     */
    virtual void execute(void) = 0;

    /**
     * @brief Returns whether or not this command has a higher precedence than operator or operand.
     * 
     * @param op string containing only the operator or operand
     * @return true if this command has a higher precedence than op
     * @return false if this command has equal or lower precedence than op
     */
    virtual bool isHigherPrecedence(std::string op) = 0;
};

#endif