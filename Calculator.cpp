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
            this->strategy_.solve(expression);
            int result = this->strategy_.result();
            std::cout << "Your result is: " << result << std::endl;
        } // end if
    } // end while
} // end start

void Calculator::setStrategy(std::string strategy)
{
    if (strategy == "factory")
    {
        this->strategy_ = Calculator_Strategy();
    }
    else if (strategy == "builder")
    {
        this->strategy_ = Calculator_Strategy();
    }
    else
    {
        throw "ERROR: unknown strategy";
    } // end if strategy
} // end setStrategy