//==============================================================================
/**
 * @file       Builder_Strategy.h
 *
 * Concrete implementation of calculator strategy that makes use of the
 * builder software design pattern.
 */
//==============================================================================

#ifndef _BUILDER_STRATEGY_H_
#define _BUILDER_STRATEGY_H_

#include <iostream>
#include <string>
#include <sstream>

#include "Calculator_Strategy.h"
// #include "Stack.h"
// #include "Array.h"
// #include "Stack_Expr_Command_Factory.h"
// #include "Expr_Command.h"

class Builder_Strategy : public Calculator_Strategy
{
public:
    Builder_Strategy();

    void solve(std::string expression);

    int result();

protected:
    int result_;
};

#endif