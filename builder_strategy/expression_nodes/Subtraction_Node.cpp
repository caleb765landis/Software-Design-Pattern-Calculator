// Subtraction_Node.cpp

#include "Subtraction_Node.h"

Subtraction_Node::Subtraction_Node(void)
{}

// Subtraction_Node::Subtraction_Node(Expr_Node *l, Expr_Node *r)
// {
//     this->left_ = l;
//     this->right_ = r;
//     this->value_ = 0;
// }

Subtraction_Node::~Subtraction_Node(void)
{
    // delete this->right_;
    // delete this->left_;
}

void Subtraction_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Subtraction_Node(*this);
}

int Subtraction_Node::get_precedence()
{
    return 1;
}