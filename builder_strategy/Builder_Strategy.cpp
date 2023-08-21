// Builder_Strategy.cpp

#include "Builder_Strategy.h"

Builder_Strategy::Builder_Strategy()
    : result_(0)
{}

void Builder_Strategy::solve(std::string expression)
{
    // create expression tree builder
    // Expr_Tree_Builder *b = new Expr_Tree_Builder();

    // // parse through expression to put it in postfix order and build tree with postfix expression
    // parse_expr(infix, *b);

    // // evaluate expression tree from builder with visitor
    // evaluate(infix, *b);

    // delete b;
}

int Builder_Strategy::result()
{
    return this->result_;
}