// Builder_Strategy.cpp

#include "Builder_Strategy.h"

Builder_Strategy::Builder_Strategy()
    : result_(0)
{}

void Builder_Strategy::solve(std::string expression)
{
    // create expression tree builder
    Expr_Tree_Builder *b = new Expr_Tree_Builder();

    // parse through expression to put it in postfix order and build tree with postfix expression
    parse_expr(expression, *b);

    // evaluate expression tree from builder with visitor
    // evaluate(*b);

    delete b;
}

int Builder_Strategy::result()
{
    return this->result_;
}

void Builder_Strategy::parse_expr(const std::string &infix, Expr_Tree_Builder &b)
{
    // create an input stream parser
    std::istringstream input(infix);

    // create a string called token for current token in string stream
    std::string token;

    b.start_expression();

    // while it is not the end of input stream parser
    bool keepConverting = true;
    while (keepConverting)
    {
        // current input goes into token
        input >> token;

        // use builder to create an expression node and set it to node
        if (token == "+")
        {
            b.build_add_operator();
        }
        else if (token == "-")
        {
            b.build_sub_operator();
        }
        else if (token == "*")
        {
            b.build_mult_operator();
        }
        else if (token == "/")
        {
            b.build_div_operator();
        }
        else if (token == "%")
        {
            b.build_mod_operator();
        }
        else if (token == "(")
        {
            // string expression of whatever is inside parenthesis
            std::string expr = "";

            // create expression tree builder and give it access to nums
            Expr_Tree_Builder *temp_b = new Expr_Tree_Builder();

            bool keepIterating = true;
            while (keepIterating)
            {
                input >> token;
                if (token == ")")
                {
                    // trim last space off of expression so it doesn't mess up ss parsing
                    // finalExpr is just the expression without the extra space at the end
                    std::string finalExpr = "";
                    for (int i = 0; i < expr.length() - 1; i++)
                    {
                        finalExpr = finalExpr + expr[i];
                    }

                    // parse through expression to put it in postfix order and build tree with postfix expression
                    parse_expr(expr, *temp_b);

                    // evaluate expression tree from builder with visitor
                    evaluate(*temp_b);
                }
                else
                {
                    expr = expr + token + " ";
                } // end if
            }     // end while
        }         // end if parentheses
        else
        {
            b.build_number(stoi(token));
        }

        if (input.eof())
        {
            keepConverting = false;
        }
    } // end while

    b.end_expression();
}

int Builder_Strategy::evaluate(Expr_Tree_Builder &b)
{
    Eval_Expr_Tree eval;
    b.tree_->get_head().accept(eval);

    // eval.Visit_Addition_Node(eval);
    // eval.Visit_Number_Node(eval);
    std::cout << b.tree_->get_head().value_ << std::endl;

    int result = eval.result();
    std::cout << result << std::endl;

    // delete b.tree_;
}