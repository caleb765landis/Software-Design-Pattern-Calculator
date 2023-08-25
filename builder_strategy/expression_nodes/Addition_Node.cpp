// Addition_Node.cpp


#include "Addition_Node.h"

Addition_Node::Addition_Node(void)
{
    this->left_ = nullptr;
    this->right_ = nullptr;
}

Addition_Node::~Addition_Node(void)
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

void Addition_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Addition_Node(*this);
}

int Addition_Node::get_precedence()
{
    return 1;
}