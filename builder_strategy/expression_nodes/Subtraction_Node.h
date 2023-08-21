//==============================================================================
/**
 * @file    Subtraction_Node.h
 *
 */
//==============================================================================

#ifndef _SUBTRACTION_NODE_H_
#define _SUBTRACTION_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Subtraction_Node : public Binary_Expr_Node
{
public:
    Subtraction_Node(void);
    // Subtraction_Node(Expr_Node *l, Expr_Node *r);
    ~Subtraction_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif