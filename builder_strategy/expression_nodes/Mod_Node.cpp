// Mod_Node.cpp

#include "Mod_Node.h"

Mod_Node::Mod_Node(void)
{}

// Mod_Node::Mod_Node(Expr_Node *l, Expr_Node *r)
// {
//     this->left_ = l;
//     this->right_ = r;
//     this->value_ = 0;
// }

Mod_Node::~Mod_Node(void)
{
    // delete this->right_;
    // delete this->left_;
}

void Mod_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Mod_Node(*this);
}

int Mod_Node::get_precedence()
{
    return 1;
}