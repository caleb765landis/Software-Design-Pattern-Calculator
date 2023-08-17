//==============================================================================
/**
 * @file       Sub_Command.h
 *
 * Command for handling subtraction operators in a postfix expression.
 */
//==============================================================================

#ifndef _SUB_COMMAND_H_
#define _SUB_COMMAND_H_

#include "Expr_Command.h"

class Sub_Command : public Expr_Command
{
public:
    Sub_Command(Stack<int> &s);

    void execute(void);

    bool isHigherPrecedence(std::string op);

private:
    Stack<int> &s_;
};

#endif