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
    evaluate(*b);

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

            // number of sub-expressions within parentheses
            // increases every time an open parentheses is found
            // decreases every time an closed parentheses is found
            // starts at 1 because current token is already a found open parentheses
            int numSubExpr = 1;

            bool keepIterating = true;
            while (keepIterating)
            {
                input >> token;

                if (token == "(")
                {
                    numSubExpr++;
                }
                else if (token == ")")
                {
                    numSubExpr--;

                    if (numSubExpr == 0)
                    {
                        // trim last space off of expression so it doesn't mess up ss parsing
                        // finalExpr is just the expression without the extra space at the end
                        std::string finalExpr = "";
                        for (int i = 0; i < expr.length() - 1; i++)
                        {
                            finalExpr = finalExpr + expr[i];
                        }

                        // parse through expression to put it in postfix order and build tree with postfix expression
                        parse_expr(finalExpr, *temp_b);

                        // evaluate expression tree from builder with visitor
                        evaluate(*temp_b);

                        // build a number node with result of all expressions within currently found parentheses
                        b.build_number(this->result_);

                        delete temp_b;

                        keepIterating = false;
                    } // end if
                } // end if
                else
                {
                    expr = expr + token + " ";
                } // end if
            }     // end while
        }         // end if open parentheses
        else if (token == ")")
        {
            // do nothing
        }
        else {
            b.build_number(stoi(token));
        }

        if (input.eof())
        {
            keepConverting = false;
        }
    } // end while

    b.end_expression();
}

void Builder_Strategy::evaluate(Expr_Tree_Builder &b)
{
    Eval_Expr_Tree eval;
    b.tree_->get_head().accept(eval);
    this->result_ = eval.result();
}