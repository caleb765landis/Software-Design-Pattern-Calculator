//==============================================================================
/**
 * @file       Mod_Command.h
 *
 * Command for handling modulus operators in a postfix expression.
 */
//==============================================================================

#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Expr_Command.h"

class Mod_Command : public Expr_Command
{
public:
    Mod_Command(Stack<int> &s);

    void execute(void);

    bool isHigherPrecedence(std::string op);

private:
    Stack<int> &s_;
};

#endif