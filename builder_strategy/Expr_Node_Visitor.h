//==============================================================================
/**
 * @file    Expr_Node_Visitor.h
 *
 */
//==============================================================================

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Mod_Node;

#include <iostream>

class Expr_Node_Visitor
{
public:
    virtual void Visit_Addition_Node(Addition_Node &node) = 0;
    virtual void Visit_Subtraction_Node(Subtraction_Node &node) = 0;
    virtual void Visit_Multiplication_Node(Multiplication_Node &node) = 0;
    virtual void Visit_Division_Node(Division_Node &node) = 0;
    virtual void Visit_Mod_Node(Mod_Node &node) = 0;
};

#endif