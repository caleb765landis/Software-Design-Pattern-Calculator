// Division_Node.cpp

#include "Division_Node.h"

Division_Node::Division_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Division_Node::~Division_Node(void)
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

void Division_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Division_Node(*this);
}

int Division_Node::get_precedence()
{
    return 2;
}