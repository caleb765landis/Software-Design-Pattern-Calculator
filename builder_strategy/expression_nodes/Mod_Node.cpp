// Mod_Node.cpp

#include "Mod_Node.h"

Mod_Node::Mod_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Mod_Node::~Mod_Node(void)
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

void Mod_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Mod_Node(*this);
}

int Mod_Node::get_precedence()
{
    return 2;
}