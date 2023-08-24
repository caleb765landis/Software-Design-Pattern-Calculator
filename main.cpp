//==============================================================================
/**
 * @file       main.cpp
 *
 * Client code to make use of Calculator class
 */
//==============================================================================

#include <iostream>
#include <string>

#include "./drivers/Driver.h"
#include "Calculator.h"

std::string chooseStrategy();

int main(int argc, char *argv[])
{
    std::string strategy = "";

    // get commandline arguments to determine which strategy to use
    try
    {
        // if only commandline argument is running main executable 
        // or if arguments are more than the two expected, throw an error
        if (argc == 1 || argc > 2)
        {
            throw "ERROR: incorrect number of arguments";
        }

        std::string temp = argv[1];

        // if argument is for factory strategy, set that as the strategy to use
        if (temp == "-f")
        {
            strategy = "factory";
        }
        // if argument is for builder strategy, set that as the strategy to use
        else if (temp == "-b")
        {
            strategy = "builder";
        }
        // if argument is for driver, run all tests
        // then have user choose which strategy to continue with
        else if (temp == "-d")
        {
            // Create driver instance
            Driver driver;

            // Test all classes
            driver.testAll();

            // Choose strategy to continue testing calculator client
            strategy = chooseStrategy();
        }
        // if argument doesn't match any expected conditions, throw an error
        else
        {
            throw "ERROR: unknown strategy";
        }
    }
    // catch and report errors and have user choose which strategy to use
    catch (const char *exp)
    {
        std::cout << exp << std::endl << std::endl;
        strategy = chooseStrategy();
    }

    std::cout << "================================================================" << std::endl;
    std::cout << "Starting calculator with " << strategy << " strategy." << std::endl;
    std::cout << "================================================================" << std::endl << std::endl;

    Calculator calc(strategy);

    calc.start();

    // return from main wihout error
    return 0;
}

/**
 * @brief has user input which strategy they want to continue with
 * 
 * @return std::string the strategy chosen
 *         will return either "factory" or "builder"
 */
std::string chooseStrategy()
{
    bool keepGoing = true;
    std::string strategy = "";

    while (keepGoing)
    {
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