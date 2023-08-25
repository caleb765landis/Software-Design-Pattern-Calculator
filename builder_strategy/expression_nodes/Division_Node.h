//==============================================================================
/**
 * @file    Division_Node.h
 * 
 */
//==============================================================================

#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include "Binary_Expr_Node.h"
#include "../Expr_Node_Visitor.h"

class Division_Node : public Binary_Expr_Node
{
public:
    /**
     * @brief Construct a new Addition_Node object.
     *        Sets left and right children to nullptr.
     */
    Division_Node(void);

    /**
     * @brief Destroy the Addition_Node object.
     *        Deletes left and right children if they are not null.
     */
    ~Division_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif