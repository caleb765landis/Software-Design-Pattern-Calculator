//==============================================================================
/**
 * @file    Multiplication_Node.h
 *
 */
//==============================================================================

#ifndef _MULTIPLICATION_NODE_H_
#define _MULTIPLICATION_NODE_H_

#include "Binary_Expr_Node.h"
#include "../Expr_Node_Visitor.h"

class Multiplication_Node : public Binary_Expr_Node
{
public:
    /**
     * @brief Construct a new Addition_Node object.
     *        Sets left and right children to nullptr.
     */
    Multiplication_Node(void);

    /**
     * @brief Destroy the Addition_Node object.
     *        Deletes left and right children if they are not null.
     */
    ~Multiplication_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif