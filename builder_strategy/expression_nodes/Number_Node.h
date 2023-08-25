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
    /**
     * @brief Construct a new Addition_Node object.
     *        Sets node's integer value.
     * 
     * @param val the integer to set node's value_
     */
    Number_Node(int val);

    /**
     * @brief Destroy the Addition_Node object.
     *        All number nodes should be leaves, so they should not have children to delete.
     */
    ~Number_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual bool is_num();
    virtual int get_precedence();
};

#endif