//==============================================================================
/**
 * @file    Expr_Tree_Builder.h
 *
 * Concrete builder class that builds Expr_Tree of composite Expr_Nodes.
 */
//==============================================================================

#ifndef _Expr_Tree_Builder_H_
#define _Expr_Tree_Builder_H_

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "../utils/Stack.h"

#include "./expression_nodes/Expr_Node.h"
#include "./expression_nodes/Number_Node.h"
#include "./expression_nodes/Addition_Node.h"
#include "./expression_nodes/Subtraction_Node.h"
#include "./expression_nodes/Multiplication_Node.h"
#include "./expression_nodes/Division_Node.h"
#include "./expression_nodes/Mod_Node.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
    Expr_Tree_Builder(void);
    ~Expr_Tree_Builder(void);

    virtual void start_expression(void);
    virtual void end_expression(void);
    virtual Expr_Tree* get_expression_tree(void);
    
    virtual void build_number(int n);

    virtual void build_add_operator(void);
    virtual void build_sub_operator(void);
    virtual void build_mult_operator(void);
    virtual void build_div_operator(void);
    virtual void build_mod_operator(void);

    friend class Builder_Strategy;

private:
    Expr_Tree* tree_;
    Stack<Expr_Node*> nodes_; // stack of fully build Expr_Nodes
    Stack<Expr_Node*> tempOps_; // stack of temporary operator Expr_Nodes

   void build_binary_expression(Expr_Node* n);
};

#endif