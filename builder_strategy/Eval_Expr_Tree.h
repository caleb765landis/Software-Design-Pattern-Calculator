//==============================================================================
/**
 * @file    Eval_Expr_Tree.h
 *
 * Visits every node that accepts the visitor, then applies the node's corresponding operation.
 */
//==============================================================================

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

#include "./expression_nodes/Addition_Node.h"
#include "./expression_nodes/Subtraction_Node.h"
#include "./expression_nodes/Multiplication_Node.h"
#include "./expression_nodes/Division_Node.h"
#include "./expression_nodes/Mod_Node.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
    Eval_Expr_Tree(void);
    virtual ~Eval_Expr_Tree(void);

    virtual void Visit_Addition_Node(Addition_Node &node);
    virtual void Visit_Subtraction_Node(Subtraction_Node &node);
    virtual void Visit_Multiplication_Node(Multiplication_Node &node);
    virtual void Visit_Division_Node(Division_Node &node);
    virtual void Visit_Mod_Node(Mod_Node &node);

    int result(void) const;

private:
    int result_;
};

#endif