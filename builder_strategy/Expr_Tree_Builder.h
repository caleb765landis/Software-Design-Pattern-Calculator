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
    /**
     * @brief Construct a new Expr_Tree_Builder object.
     *        Sets tree_ to nullptr.
     * 
     */
    Expr_Tree_Builder(void);

    /**
     * @brief Destroy the Expr_Tree_Builder object and heap instance of tree_.
     * 
     */
    ~Expr_Tree_Builder(void);

    /**
     * @brief creates expression tree instance on heap
     * 
     */
    virtual void start_expression(void);

    /**
     * @brief Finishes building expression tree and sets tree_'s head node
     * 
     */
    virtual void end_expression(void);

    /**
     * @brief Gets pointer to the expression tree 
     * 
     * @return Expr_Tree* 
     */
    virtual Expr_Tree* get_expression_tree(void);
    
    virtual void build_number(int n);

    virtual void build_add_operator(void);
    virtual void build_sub_operator(void);
    virtual void build_mult_operator(void);
    virtual void build_div_operator(void);
    virtual void build_mod_operator(void);

    friend class Builder_Strategy;

private:
    Expr_Tree* tree_; // the actual expression tree
    Stack<Expr_Node*> nodes_; // stack of pointers to fully built Expr_Nodes
    Stack<Expr_Node*> tempOps_; // stack of pointers to unfinished operator Expr_Nodes

    /**
     * @brief template method for operators to execute building binary expression nodes
     * 
     * @param n the operator expression node
     */
    void build_binary_expression(Expr_Node* n);
};

#endif