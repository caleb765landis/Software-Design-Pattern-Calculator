//==============================================================================
/**
 * @file    Expr_Node.h
 *
 * Parent class for composite nodes used by Expr_Tree data structure.
 */
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

// Expr_Node_Visitor foward declaration
class Expr_Node_Visitor;

#include <iostream>

class Expr_Node
{
public:

    // Methods for children to inherit for setting and getting left/right nodes
    void set_left(Expr_Node& n);
    Expr_Node& get_left();
    void set_right(Expr_Node& n);
    Expr_Node& get_right();

    /**
     * @brief used to traverse expression tree with visitor
     *
     * @param v the Expr_Node_Visitor that traverses the tree
     */
    virtual void accept(Expr_Node_Visitor& v) = 0;
    virtual bool is_num() = 0;
    virtual int get_precedence() = 0;

    friend class Eval_Expr_Tree;
    friend class Expr_Node_Visitor;
    friend class Calculator;

protected:
    Expr_Node* left_;
    Expr_Node* right_;
    int value_;
};

#endif