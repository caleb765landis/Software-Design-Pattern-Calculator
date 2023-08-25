// Subtraction_Node.cpp

#include "Subtraction_Node.h"

Subtraction_Node::Subtraction_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Subtraction_Node::~Subtraction_Node(void)
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

void Subtraction_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Subtraction_Node(*this);
}

int Subtraction_Node::get_precedence()
{
    return 1;
}