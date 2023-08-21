//==============================================================================
/**
 * @file    Multiplication_Node.h
 *
 */
//==============================================================================

#ifndef _MULTIPLICATION_NODE_H_
#define _MULTIPLICATION_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Multiplication_Node : public Binary_Expr_Node
{
public:
    Multiplication_Node(void);
    // Multiplication_Node(Expr_Node *l, Expr_Node *r);
    ~Multiplication_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif