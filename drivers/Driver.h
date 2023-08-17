//==============================================================================
/**
 * @file       Driver.h
 *
 * Driver wrapper class to test classes for Calculator's dependencies.
 */
//==============================================================================

#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include "Utils_Driver.h"

class Driver
{
public:
    Driver();

    void testAll();
    void testBaseArray();
    void testDynamicArray();
    void testFixedArray();
    void testStack();
    void testQueue();

private:
    Utils_Driver utils_;
};

#endif