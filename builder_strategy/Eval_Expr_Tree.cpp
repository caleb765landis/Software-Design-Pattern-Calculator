// Eval_Expr_Tree.cpp

#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree(void)
    : result_(0)
{}

Eval_Expr_Tree::~Eval_Expr_Tree(void) {}

void Eval_Expr_Tree::Visit_Addition_Node(Addition_Node &node)
{
    node.left_->accept(*this);
    node.right_->accept(*this);

    node.value_ = node.left_->value_ + node.right_->value_;
    this->result_ = node.value_;
}

void Eval_Expr_Tree::Visit_Subtraction_Node(Subtraction_Node &node)
{
    node.left_->accept(*this);
    node.right_->accept(*this);

    node.value_ = node.left_->value_ - node.right_->value_;
    this->result_ = node.value_;
}

void Eval_Expr_Tree::Visit_Multiplication_Node(Multiplication_Node &node)
{
    node.left_->accept(*this);
    node.right_->accept(*this);

    node.value_ = node.left_->value_ * node.right_->value_;
    this->result_ = node.value_;
}

void Eval_Expr_Tree::Visit_Division_Node(Division_Node &node)
{
    node.left_->accept(*this);
    node.right_->accept(*this);

    node.value_ = node.left_->value_ / node.right_->value_;
    this->result_ = node.value_;
}

void Eval_Expr_Tree::Visit_Mod_Node(Mod_Node &node)
{
    node.left_->accept(*this);
    node.right_->accept(*this);

    node.value_ = node.left_->value_ % node.right_->value_;
    this->result_ = node.value_;
}

int Eval_Expr_Tree::result(void) const
{
    return this->result_;
}