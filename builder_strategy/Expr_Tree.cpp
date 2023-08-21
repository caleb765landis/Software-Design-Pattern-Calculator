// Expr_Tree.cpp

#include "Expr_Tree.h"

Expr_Tree::Expr_Tree()
    : head_(nullptr) {}

Expr_Tree::~Expr_Tree() {}

void Expr_Tree::set_head(Expr_Node &n)
{
    this->head_ = &n;
}

Expr_Node& Expr_Tree::get_head()
{
    return *this->head_;
}

bool Expr_Tree::has_head()
{
    return !(this->head_ == nullptr);
}