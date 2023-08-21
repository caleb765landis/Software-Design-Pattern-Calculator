//==============================================================================
/**
 * @file    Expr_Tree.h
 *
 * Binary tree of expression node composites.
 */
//==============================================================================

#ifndef _Expr_Tree_H_
#define _Expr_Tree_H_

#include <iostream>
#include "./expression_nodes/Expr_Node.h"

class Expr_Tree
{
public:
    Expr_Tree();
    ~Expr_Tree();

    void set_head(Expr_Node &n);
    Expr_Node& get_head();

    /**
     * @brief returns true if head is an expression node
     *        returns false if head is a nullptr
     *
     * @return true
     * @return false
     */
    bool has_head();

private:
    Expr_Node* head_;
};

#endif