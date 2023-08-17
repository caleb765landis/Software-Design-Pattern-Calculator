//==============================================================================
/**
 * @file       Num_Command.h
 *
 * Command for handling numbers in a posfix expression.
 */
//==============================================================================

#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"

class Num_Command : public Expr_Command
{
public:
    Num_Command(Stack<int> &s, int n);

    void execute(void);

    bool isHigherPrecedence(std::string op);

private:
    Stack<int> &s_;
    int n_;
};

#endif