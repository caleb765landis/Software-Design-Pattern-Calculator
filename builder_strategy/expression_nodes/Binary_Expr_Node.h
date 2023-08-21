//==============================================================================
/**
 * @file    Binary_Expr_Node.h
 *
 * Child of Expr_Node. Abstract parent of operators that do binary operations (add, subtract, etc.).
 */
//==============================================================================

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node
{
public:
    // returns false because operators are not numbers
    virtual bool is_num();

    virtual void accept(Expr_Node_Visitor &v) = 0;
    virtual int get_precedence() = 0;
};

#endif