// Division_Node.cpp

#include "Division_Node.h"

Division_Node::Division_Node(void)
{}

// Division_Node::Division_Node(Expr_Node *l, Expr_Node *r)
// {
//     this->left_ = l;
//     this->right_ = r;
//     this->value_ = 0;
// }

Division_Node::~Division_Node(void)
{
    // delete this->right_;
    // delete this->left_;
}

void Division_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Division_Node(*this);
}

int Division_Node::get_precedence()
{
    return 1;
}