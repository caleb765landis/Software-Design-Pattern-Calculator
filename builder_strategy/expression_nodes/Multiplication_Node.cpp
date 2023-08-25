// Multiplication_Node.cpp

#include "Multiplication_Node.h"

Multiplication_Node::Multiplication_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Multiplication_Node::~Multiplication_Node(void)
{
    if (this->left_ != nullptr)
    {
        delete this->left_;
    }

    if (this->right_ != nullptr)
    {
        delete this->right_;
    }
}

void Multiplication_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Multiplication_Node(*this);
}

int Multiplication_Node::get_precedence()
{
    return 2;
}