// Abstract_Factory_Strategy.cpp

#include "Abstract_Factory_Strategy.h"

Abstract_Factory_Strategy::Abstract_Factory_Strategy()
    : result_(0)
{}

void Abstract_Factory_Strategy::solve(std::string expression)
{
    // create int stack called result
    Stack<int> resultStack;

    // create Stack_Expr_Command_Factory called factory passing resultStack as an argument
    Stack_Expr_Command_Factory factory(resultStack);

    // create an array of <Command *> called postfix
    Array<Expr_Command *> postfix;

    // call infix_to_postfix() passing expression, factory, and postfix as arugments
    infix_to_postfix(expression, factory, postfix);

    // evaluate postfix expression
    evaluate_postfix(postfix);

    this->result_ = resultStack.top();
}

int Abstract_Factory_Strategy::result()
{
    return this->result_;
}

void Abstract_Factory_Strategy::infix_to_postfix(const std::string &infix, Expr_Command_Factory &factory, Array<Expr_Command *> &postfix)
{
    // create an input stream parser
    std::istringstream input(infix);

    // create a string called token for current token in string stream
    std::string token;

    // create command object called cmd
    Expr_Command *cmd = 0;

    // create stack of commands called tempCmds
    Stack<Expr_Command *> tempCmds;

    // create stack of operators called tempOperators
    Stack<std::string> tempOperators;

    // while it is not the end of input stream parser
    bool keepConverting = true;
    while (keepConverting)
    {
        // current input goes into token
        input >> token;

        // use command factory to create a command and set it to cmd
        if (token == "+")
        {
            cmd = factory.create_add_command();
        }
        else if (token == "-")
        {
            cmd = factory.create_sub_command();
        }
        else if (token == "*")
        {
            cmd = factory.create_mult_command();
        }
        else if (token == "/")
        {
            cmd = factory.create_div_command();
        }
        else if (token == "%")
        {
            cmd = factory.create_mod_command();
        }
        // if token is open parentheses, create substring until matching closed parentheses
        else if (token == "(")
        {
            // string expression of whatever is inside parenthesis
            std::string expr = "";

            // create temp int stack for result of parenthesis expression
            Stack<int> tempResult;

            // create temp Stack_Expr_Command_Factory
            Stack_Expr_Command_Factory tempFactory(tempResult);

            // create a temp array of commands
            Array<Expr_Command *> tempPostfix;

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

                        infix_to_postfix(finalExpr, tempFactory, tempPostfix);
                        evaluate_postfix(tempPostfix);
                        cmd = factory.create_num_command(tempResult.top());

                        // append num command to postfix and end this loop
                        postfix.resize(postfix.size() + 1);
                        postfix[postfix.size() - 1] = cmd;

                        keepIterating = false;
                    }
                }
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
        // if token is operand, append command to end of postfix expression
        else if (isOperand(token))
        {
            cmd = factory.create_num_command(stoi(token));
            postfix.resize(postfix.size() + 1);
            postfix[postfix.size() - 1] = cmd;
        }
        else
        {
            throw "ERROR: invlaid expression";
        }

        // if token is operator
        if (isOperator(token))
        {
            // if stack is empty or operator is of greater precedence than top of stack
            if (tempCmds.is_empty() || cmd->isHigherPrecedence(token))
            {
                // push operator comand to top of stack
                tempCmds.push(cmd);
                tempOperators.push(token);
            }
            // otherwise pop from stack and append to postfix until operator has greater precedence than top of stack or stack is empty
            else
            {
                bool keepGoing = true;
                while (keepGoing)
                {
                    // check if tempCmds is empty or if cmd has higher precedence than top of stack
                    if (tempCmds.is_empty() || cmd->isHigherPrecedence(tempOperators.top()))
                    {
                        tempCmds.push(cmd);
                        tempOperators.push(token);
                        keepGoing = false;
                    }
                    else
                    {
                        // append to postfix
                        postfix.resize(postfix.size() + 1);
                        postfix[postfix.size() - 1] = tempCmds.top();

                        // pop from stack
                        tempCmds.pop();
                        tempOperators.pop();
                    } // end if
                }     // end while
            }         // end else
        }             // end if isOperator

        if (input.eof())
        {
            keepConverting = false;
        }
    } // end while

    // finish appending operators to postfix
    while (!tempCmds.is_empty())
    {
        postfix.resize(postfix.size() + 1);
        postfix[postfix.size() - 1] = tempCmds.top();
        tempCmds.pop();
    } // end while
} // end infix_to_postfix

/**
 * @param postfix
 */
void Abstract_Factory_Strategy::evaluate_postfix(Array<Expr_Command *> &postfix)
{
    // iterate through list of expression commands and execute each command
    for (int i = 0; i < postfix.size(); i++)
    {
        Expr_Command *cmd = postfix[i];
        cmd->execute();
    }
}

bool Abstract_Factory_Strategy::isOperand(const std::string &s)
{
    for (char const &ch : s)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

bool Abstract_Factory_Strategy::isOperator(const std::string &s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "%")
    {
        return true;
    }
    return false;
}