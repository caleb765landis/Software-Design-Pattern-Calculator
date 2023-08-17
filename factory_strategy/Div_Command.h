//==============================================================================
/**
 * @file       Div_Command.h
 *
 * Command for handling division operators in a postfix expression.
 */
//==============================================================================

#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Expr_Command.h"

class Div_Command : public Expr_Command
{
public:
    Div_Command(Stack<int> &s);

    void execute(void);

    bool isHigherPrecedence(std::string op);

private:
    Stack<int> &s_;
};

#endif