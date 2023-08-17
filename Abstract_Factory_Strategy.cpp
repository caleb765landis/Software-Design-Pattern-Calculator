// Abstract_Factory_Strategy.cpp

#include "Abstract_Factory_Strategy.h"

Abstract_Factory_Strategy::Abstract_Factory_Strategy()
    : result_(0)
{
    std::cout << "Created Abstract_Factory_Strategy" << std::endl;
}

void Abstract_Factory_Strategy::solve(std::string expression)
{
    // // create int stack called result
    // Stack<int> result;

    // // create Stack_Expr_Command_Factory called factory passing result as an argument
    // Stack_Expr_Command_Factory factory(result);

    // // create an array of <Command *> called postfix
    // Array<Expr_Command *> postfix;

    // // call infix_to_postfix() passing infix, factory, and postfix as arugments
    // infix_to_postfix(infix, factory, postfix);
    // // evaluate postfix expression
    // evaluate_postfix(postfix);
}

int Abstract_Factory_Strategy::result()
{
    return this->result_;
}