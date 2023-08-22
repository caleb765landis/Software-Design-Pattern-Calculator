//==============================================================================
/**
 * @file       Builder_Strategy.h
 *
 * Concrete implementation of calculator strategy that makes use of the
 * builder software design pattern.
 */
//==============================================================================

#ifndef _BUILDER_STRATEGY_H_
#define _BUILDER_STRATEGY_H_

#include <iostream>
#include <string>
#include <sstream>

#include "../Calculator_Strategy.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"

class Builder_Strategy : public Calculator_Strategy
{
public:
    /**
     * @brief Construct a new Builder_Strategy object
     *        Initializes result_ to 0
     *
     */
    Builder_Strategy();

    /**
     * @brief solves simple math expression using builder pattern and stores in result_
     *
     * @param expression
     */
    void solve(std::string expression);

    /**
     * @brief returns result_
     * 
     * @return int 
     */
    int result();

private:
    int result_;

    void parse_expr(const std::string &infix, Expr_Tree_Builder &b);
    int evaluate(Expr_Tree_Builder &b);
};

#endif