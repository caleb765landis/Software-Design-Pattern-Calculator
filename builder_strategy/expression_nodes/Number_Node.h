//==============================================================================
/**
 * @file    Number_Node.h
 *
 */
//==============================================================================

#ifndef _Number_Node_H_
#define _Number_Node_H_

#include "Expr_Node.h"
#include "../Expr_Node_Visitor.h"

class Number_Node : public Expr_Node
{
public:
    Number_Node(int val);
    ~Number_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual bool is_num();
    virtual int get_precedence();
};

#endif