//==============================================================================
/**
 * @file    Mod_Node.h
 * 
 */
//==============================================================================

#ifndef _MOD_NODE_H_
#define _MOD_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Mod_Node : public Binary_Expr_Node
{
public:
    Mod_Node(void);
    // Mod_Node(Expr_Node *l, Expr_Node *r);
    ~Mod_Node(void);

    virtual void accept(Expr_Node_Visitor &v);
    virtual int get_precedence();
};

#endif