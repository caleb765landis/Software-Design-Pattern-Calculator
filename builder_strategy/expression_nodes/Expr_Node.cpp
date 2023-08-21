// Expr_Node.cpp

#include "Expr_Node.h"

void Expr_Node::set_left(Expr_Node& n)
{
    this->left_ = &n;
}

Expr_Node& Expr_Node::get_left()
{
    return *this->left_;
}

void Expr_Node::set_right(Expr_Node& n)
{
    this->right_ = &n;
}

Expr_Node& Expr_Node::get_right()
{
    return *this->right_;
}