//==============================================================================
/**
 * @file       Mult_Command.h
 *
 * Command for handling multiplication operators in a postfix expression.
 */
//==============================================================================

#ifndef _MULT_COMMAND_H_
#define _MULT_COMMAND_H_

#include "Expr_Command.h"

class Mult_Command : public Expr_Command
{
public:
    Mult_Command(Stack<int> &s);

    void execute(void);

    bool isHigherPrecedence(std::string op);

private:
    Stack<int> &s_;
};

#endif