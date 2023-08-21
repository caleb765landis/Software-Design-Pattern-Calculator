//==============================================================================
/**
 * @file    Division_Node.h
 * 
 */
//==============================================================================

#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Division_Node : public Binary_Expr_Node
{
public:
    Division_Node(void);
    // Division_Node(Expr_Node *l, Expr_Node *r);
    ~Division_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif