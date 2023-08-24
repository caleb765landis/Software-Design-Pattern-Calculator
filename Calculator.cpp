// Calculator.cpp

#include "Calculator.h"

Calculator::Calculator()
{
    setStrategy("factory");
}

Calculator::Calculator(std::string strategy)
{
    try {
        setStrategy(strategy);
    }
    catch (const char *exp)
    {
        std::cout << exp << std::endl;
        setStrategy("factory");
    }
}

Calculator::~Calculator()
{
    delete this->strategy_;
}

void Calculator::start()
{
    bool keepGoing = true;
    while (keepGoing)
    {

        // get input from STDIN and put it in a string called expression
        std::string expression;
        std::cout << "Please input your expression: ";
        std::getline(std::cin, expression);

        if (expression == "QUIT")
        {
            keepGoing = false;
        }
        else
        {
            try
            {
                // try to solve the expression with the chosen strategy
                this->strategy_->solve(expression);

                // get result from strategy and output it
                int result = this->strategy_->result();
                std::cout << "Your result is: " << result << std::endl;
            }
            // catch and report errors and have user choose which strategy to use
            catch (const char *exp)
            {
                std::cout << exp << std::endl << std::endl;
            }
        } // end if
    } // end while
} // end start

void Calculator::setStrategy(std::string strategy)
{
    if (strategy == "factory")
    {
        this->strategy_ = new Abstract_Factory_Strategy();
    }
    else if (strategy == "builder")
    {
        this->strategy_ = new Builder_Strategy();
    }
    else
    {
        throw "ERROR: unknown strategy";
    } // end if strategy
} // end setStrategy