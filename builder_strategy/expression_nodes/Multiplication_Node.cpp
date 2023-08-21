// Multiplication_Node.cpp

#include "Multiplication_Node.h"

Multiplication_Node::Multiplication_Node(void)
{}

// Multiplication_Node::Multiplication_Node(Expr_Node *l, Expr_Node *r)
// {
//     this->left_ = l;
//     this->right_ = r;
//     this->value_ = 0;
// }

Multiplication_Node::~Multiplication_Node(void)
{
    // delete this->right_;
    // delete this->left_;
}

void Multiplication_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Multiplication_Node(*this);
}

int Multiplication_Node::get_precedence()
{
    return 1;
}