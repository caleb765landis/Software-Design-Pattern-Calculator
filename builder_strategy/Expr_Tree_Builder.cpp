// Expr_Tree_Builder.cpp
//
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Expr_Tree_Builder.h"

Expr_Tree_Builder::Expr_Tree_Builder(void)
    : tree_(nullptr),
      temp_(nullptr)
{
}

Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
    delete this->tree_;
}

void Expr_Tree_Builder::start_expression()
{
    this->tree_ = new Expr_Tree();
    this->temp_ = new Expr_Tree();
}

Expr_Tree *Expr_Tree_Builder::get_expression(void)
{
    return this->tree_;
}

void Expr_Tree_Builder::build_number(int n)
{
    std::cout << "building number" << std::endl;

    Number_Node *num = new Number_Node(n);

    // if head is null, set number to head
    if (!(this->tree_->has_head()))
    {
        this->tree_->set_head(*num);
        return;
    }

    // if temp tree isn't null, set number to temp's right child
    if (this->temp_->has_head())
    {
        this->temp_->get_head().set_right(*num);

        // // set temp's left child to tree's head

        // // ??
        // // set tree's head to temp's head

        // set temp to nullptr
    }
}

void Expr_Tree_Builder::build_binary_expression(Binary_Expr_Node &n)
{
    std::cout << "building binary expression" << std::endl;

    // if head is a number
    // add n to temp tree
    // set temp's left to tree's head

    // else if n has higher precedence than tree's head node
    // n is set to temp's head
    // tree's head is set temp's right

    // else if n has lower precedence than tree's head node
    // n is set to temp's head
    // tree's right is set to temp's left
    // tree's right is set to temp's head

    // // if head is null, set binary node to head
    // if (!(this->tree_->has_head()))
    // {
    //     this->tree_->set_head(n);
    //     return;
    // }

    // // if head is number
    // if (this->tree_->get_head().is_num())
    // {
    //     // set binary node's left child to tree's head
    //     n.set_left(this->tree_->get_head());
    //     // set temp's head to binary node
    //     this->temp_->set_head(n);
    //     // set tree's head to binary node
    //     this->tree_->set_head(n.get_left());

    //     return;
    // }

    // // if temp is not null
    // if (this->temp_->has_head())
    // {
    //     // check if binary node has higher precedence than temp's head
    //     if (n.get_precedence() > this->temp_->get_head().get_precedence())
    //     {
    //         // set binary node's left child to temp's head's right child
    //         n.set_left(this->temp_->get_head().get_right());
    //         // set temp's head's right child to binary node
    //         this->temp_->get_head().set_right(n);
    //         // set temp's head to binary node
    //         this->temp_->set_head(n);

    //         return;
    //     }
    // }

    // //set binary node's left child to tree's head
    // n.set_left(this->tree_->get_head());

    // // set binary node to tree's and temp's heads
    // this->tree_->set_head(n);
    // this->temp_->set_head(n);
}

void Expr_Tree_Builder::build_add_operator(void)
{
    Addition_Node *add = new Addition_Node();

    build_binary_expression(*add);
}

void Expr_Tree_Builder::build_sub_operator(void)
{
    Subtraction_Node *sub = new Subtraction_Node();

    build_binary_expression(*sub);
}

void Expr_Tree_Builder::build_mult_operator(void)
{
    Multiplication_Node *mult = new Multiplication_Node();

    build_binary_expression(*mult);
}

void Expr_Tree_Builder::build_div_operator(void)
{
    Division_Node *div = new Division_Node();

    build_binary_expression(*div);
}

void Expr_Tree_Builder::build_mod_operator(void)
{
    Mod_Node *mod = new Mod_Node();

    build_binary_expression(*mod);
}