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

    /**
     * @brief parses through expression and builds expression tree with builder
     * 
     * @param expression the string to parse through
     * @param b the expression tree builder
     */
    void parse_expr(const std::string& expression, Expr_Tree_Builder& b);

    /**
     * @brief uses a concrete visitor instance to traverse through tree and calculate result
     * 
     * @param b the builder instance containing the built expression tree
     */
    void evaluate(Expr_Tree_Builder& b);

    /**
     * @brief checks if a token is a number
     * 
     * @param s the string to parse through
     * 
     * @return true if all of s is a number
     * @return false if s is empty or part of it is not a number
     */
    bool is_number(const std::string &s);
};

#endif