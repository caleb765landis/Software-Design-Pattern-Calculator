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

#include "./utils/Base_Array.h"
#include "./utils/Array.h"
#include "./utils/Fixed_Array.h"
#include "./utils/Stack.h"
#include "./utils/Queue.h"

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
};

#endif