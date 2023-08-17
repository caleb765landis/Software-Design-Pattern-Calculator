//==============================================================================
/**
 * @file       Utils_Driver.h
 *
 * Utils_Driver class to test utility classes.
 */
//==============================================================================

#ifndef _UTILS_DRIVER_H_
#define _UTILS_DRIVER_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include "../utils/Base_Array.h"
#include "../utils/Array.h"
#include "../utils/Fixed_Array.h"
#include "../utils/Stack.h"
#include "../utils/Queue.h"

class Utils_Driver
{
public:
    Utils_Driver();

    void testAll();
    void testBaseArray();
    void testDynamicArray();
    void testFixedArray();
    void testStack();
    void testQueue();
};

#endif