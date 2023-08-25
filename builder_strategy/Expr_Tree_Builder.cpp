// Expr_Tree_Builder.cpp

#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder(void)
    : tree_(nullptr)
    //   temp_(nullptr)
{
}

Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
    delete this->tree_;
}

void Expr_Tree_Builder::start_expression()
{
    // reset expression tree if one already exists
    if (this->tree_ != nullptr)
    {
        delete this->tree_;
    }

    this->tree_ = new Expr_Tree();
}

void Expr_Tree_Builder::end_expression()
{
    // while top of tempOps_ is not empty
    // finish pushing to nodes_ from tempOps_
    while (!tempOps_.is_empty())
    {
        // get top of tempOps_ then pop tempOps
        Expr_Node *temp = tempOps_.top();
        tempOps_.pop();

        // set n's right child to top of nodes_ then pop nodes_
        temp->set_right(*nodes_.top());
        nodes_.pop();

        // set n's left child to top of nodes_ then pop nodes_
        temp->set_left(*nodes_.top());
        nodes_.pop();

        // push temp to nodes
        nodes_.push(temp);
    }

    // expression tree is finally built on nodes_ stack,
    // so set tree_'s head to the nodes_'s top
    Expr_Node* head = this->nodes_.top();
    this->tree_->set_head(*head);
}

Expr_Tree* Expr_Tree_Builder::get_expression_tree(void)
{
    return this->tree_;
}

void Expr_Tree_Builder::build_number(int n)
{
    Number_Node* num = new Number_Node(n);

    nodes_.push(num);
}

void Expr_Tree_Builder::build_binary_expression(Expr_Node* n)
{
    // while temp_ stack is not empty and top of temp_ stack has higher or equal precedence than n,
    // finish building the operator node by setting its children
    while (!tempOps_.is_empty() && tempOps_.top()->get_precedence() >= n->get_precedence())
    {
        // get top of tempOps_ then pop tempOps_
        Expr_Node* temp = tempOps_.top();
        tempOps_.pop();

        // set n's right child to top of nodes_ then pop nodes_
        temp->set_right(*nodes_.top());
        nodes_.pop();

        // set n's left child to top of nodes_ then pop nodes_
        temp->set_left(*nodes_.top());
        nodes_.pop();

        // push temp to nodes
        nodes_.push(temp);
    }

    // push n to tempOps_
    tempOps_.push(n);

}

void Expr_Tree_Builder::build_add_operator(void)
{
    Addition_Node* add = new Addition_Node();

    build_binary_expression(add);
}

void Expr_Tree_Builder::build_sub_operator(void)
{
    Subtraction_Node* sub = new Subtraction_Node();

    build_binary_expression(sub);
}

void Expr_Tree_Builder::build_mult_operator(void)
{
    Multiplication_Node* mult = new Multiplication_Node();

    build_binary_expression(mult);
}

void Expr_Tree_Builder::build_div_operator(void)
{
    Division_Node* div = new Division_Node();

    build_binary_expression(div);
}

void Expr_Tree_Builder::build_mod_operator(void)
{
    Mod_Node* mod = new Mod_Node();

    build_binary_expression(mod);
}
