//==============================================================================
/**
 * @file    Addition_Node.h
 *
 */
//==============================================================================

#ifndef _ADDITION_NODE_H_
#define _ADDITION_NODE_H_

#include "Binary_Expr_Node.h"
#include "../Expr_Node_Visitor.h"

class Addition_Node : public Binary_Expr_Node
{
public:
    Addition_Node(void);
    // Addition_Node(Expr_Node *l, Expr_Node *r);
    ~Addition_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif