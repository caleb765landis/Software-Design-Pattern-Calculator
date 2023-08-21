// Number_Node.cpp

#include "Number_Node.h"

Number_Node::Number_Node(int val)
{
    this->value_ = val;
}

Number_Node::~Number_Node(void) {}

void Number_Node::accept(Expr_Node_Visitor &v){};

bool Number_Node::is_num()
{
    return true;
}

int Number_Node::get_precedence()
{
    return 0;
}