//==============================================================================
/**
 * @file       Expr_Command_Factory.h
 *
 * Abstract parent class for abstract factory that creates commands for expression operators and operands.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

class Num_Command;
class Add_Command;
class Sub_Command;
class Mult_Command;
class Div_Command;
class Mod_Command;

class Expr_Command_Factory
{
public:
    Expr_Command_Factory();

    virtual ~Expr_Command_Factory(void) = 0;

    virtual Num_Command* create_num_command(int num) = 0;

    virtual Add_Command* create_add_command(void) = 0;

    virtual Sub_Command* create_sub_command(void) = 0;

    virtual Mult_Command* create_mult_command(void) = 0;

    virtual Div_Command* create_div_command(void) = 0;

    virtual Mod_Command* create_mod_command(void) = 0;

private:
    // prevent the following operations
    Expr_Command_Factory(const Expr_Command_Factory &);
    const Expr_Command_Factory& operator=(const Expr_Command_Factory &);
};

#endif