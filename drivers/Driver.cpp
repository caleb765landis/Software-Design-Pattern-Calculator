// Driver.cpp

#include "Driver.h"

Driver::Driver()
{
    this->utils_ = Utils_Driver();
}

void Driver::testAll()
{
    testBaseArray();
    testDynamicArray();
    testFixedArray();
    testStack();
    testQueue();
}

void Driver::testBaseArray()
{
    this->utils_.testBaseArray();
}

void Driver::testDynamicArray()
{
    this->utils_.testDynamicArray();
}

void Driver::testFixedArray()
{
    this->utils_.testFixedArray();
}
void Driver::testStack()
{
    this->utils_.testStack();
}

void Driver::testQueue()
{
    this->utils_.testQueue();
}