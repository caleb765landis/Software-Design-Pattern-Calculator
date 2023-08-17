//==============================================================================
/**
 * @file       Add_Command.h
 *
 * Command for handling addition operators in a postfix expression.
 */
//==============================================================================

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Expr_Command.h"

class Add_Command : public Expr_Command
{
public:
    Add_Command(Stack<int> &s);

    void execute(void);

    bool isHigherPrecedence(std::string op);

private:
    Stack<int> &s_;
};

#endif