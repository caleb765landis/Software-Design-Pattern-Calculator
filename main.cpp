//==============================================================================
/**
 * @file       main.cpp
 *
 * Client code to make use of Calculator class
 */
//==============================================================================

#include <iostream>
#include <string>

// #include "Calculator.h"

std::string chooseStrategy();

int main(int argc, char *argv[])
{
    std::string strategy = "";

    try {
        if (argc == 1 || argc > 2) {
            throw "ERROR: incorrect number of arguments";
        }

        std::string temp = argv[1];

        if (temp == "-f")
        {
            strategy = "factory";
        }
        else if (temp == "-b")
        {
            strategy = "builder";
        }
        else
        {
            throw "ERROR: unknown strategy";
        }
    }
    catch (const char *exp) {
        std::cout << exp << std::endl << std::endl;
        strategy = chooseStrategy();
    }

    std::cout << "================================================================" << std::endl;
    std::cout << "Starting calculator with " << strategy << " strategy." << std::endl;
    std::cout << "================================================================" << std::endl << std::endl;

    // Calculator calc;

    // calc.start();

    // return from main wihout error
    return 0;
}

std::string chooseStrategy() {
    bool keepGoing = true;
    std::string strategy = "";

    while (keepGoing) {
        std::cout << "Choose a strategy." << std::endl;
        std::cout << "Abstract Factory Strategy: -f" << std::endl;
        std::cout << "Builder Strategy: -b" << std::endl << std::endl;

        std::string strategyInput = "";
        std::cout << "Enter strategy: ";
        std::getline(std::cin, strategyInput);
        std::cout << std::endl;

        if (strategyInput == "-f")
        {
            keepGoing = false;
            strategy = "factory";
        }
        else if (strategyInput == "-b")
        {
            keepGoing = false;
            strategy = "builder";
        }
        else
        {
            std::cout << "ERROR: unknown strategy" << std::endl;
            std::cout << "Please enter a valid strategy." << std::endl << std::endl;
        }
    }

    return strategy;
}