// Stack_Expr_Command_Factory.cpp

#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(Stack<int> &stack)
    : Expr_Command_Factory(),
      stack_(stack)
{}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void) {}

Num_Command* Stack_Expr_Command_Factory::create_num_command(int num)
{
    Num_Command* numCmd = new Num_Command(stack_, num);
    return numCmd;
}

Add_Command* Stack_Expr_Command_Factory::create_add_command(void)
{
    Add_Command* addCmd = new Add_Command(stack_);
    return addCmd;
}

Sub_Command* Stack_Expr_Command_Factory::create_sub_command(void)
{
    Sub_Command* subCmd = new Sub_Command(stack_);
    return subCmd;
}

Mult_Command* Stack_Expr_Command_Factory::create_mult_command(void)
{
    Mult_Command* multCmd = new Mult_Command(stack_);
    return multCmd;
}

Div_Command* Stack_Expr_Command_Factory::create_div_command(void)
{
    Div_Command* divCmd = new Div_Command(stack_);
    return divCmd;
}

Mod_Command* Stack_Expr_Command_Factory::create_mod_command(void)
{
    Mod_Command* modCmd = new Mod_Command(stack_);
    return modCmd;
}