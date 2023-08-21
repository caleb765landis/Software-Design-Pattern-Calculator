// Addition_Node.cpp


#include "Addition_Node.h"

Addition_Node::Addition_Node(void)
{}

// Addition_Node::Addition_Node(Expr_Node *l, Expr_Node *r)
// {
//     this->left_ = l;
//     this->right_ = r;
//     this->value_ = 0;
// }

Addition_Node::~Addition_Node(void)
{
    // delete this->right_;
    // delete this->left_;
}

void Addition_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Addition_Node(*this);
}

int Addition_Node::get_precedence()
{
    return 1;
}