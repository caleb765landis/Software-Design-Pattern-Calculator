//==============================================================================
/**
 * @file       Stack_Expr_Command_Factory.h
 *
 * Concrete implementation of abstract factory that creates commands for expression operators and operands.
 */
//==============================================================================

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"
#include "../utils/Stack.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mult_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"

class Stack_Expr_Command_Factory : virtual public Expr_Command_Factory
{
public:
    Stack_Expr_Command_Factory(Stack<int> &stack);
    ~Stack_Expr_Command_Factory(void);

    Num_Command* create_num_command(int num);
    Add_Command* create_add_command(void);
    Sub_Command* create_sub_command(void);
    Mult_Command* create_mult_command(void);
    Div_Command* create_div_command(void);
    Mod_Command* create_mod_command(void);

private:
    Stack<int> &stack_;
};

#endif