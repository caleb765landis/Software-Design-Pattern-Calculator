//==============================================================================
/**
 * @file    Expr_Builder.h
 *
 * Abstract parent class for expression builder that builds a tree of composite expression nodes.
 */
//==============================================================================

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include <iostream>
#include "./expression_nodes/Binary_Expr_Node.h"

class Expr_Builder
{
public:
    virtual void start_expression(void) = 0;
    virtual void end_expression(void) = 0;
    virtual void build_number(int n) = 0;
    // virtual void build_binary_expression(Binary_Expr_Node &n) = 0;
    virtual void build_add_operator(void) = 0;
    virtual void build_sub_operator(void) = 0;
    virtual void build_mult_operator(void) = 0;
    virtual void build_div_operator(void) = 0;
    virtual void build_mod_operator(void) = 0;
    // virtual Expr_Tree* get_expression(void) = 0; 
};

#endif