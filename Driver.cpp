// Driver.cpp

#include "Driver.h"

Driver::Driver() {}

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
    std::cout << "BASE_ARRAY TEST" << std::endl
              << std::endl;

    Base_Array<int> arrayNull;

    // test array with length constructor
    // also test set and get methods in bounds
    Base_Array<int> array(1);
    array.set(0, 3);
    std::cout << "array.get(0): " << array.get(0) << std::endl
              << std::endl;

    // test set and get methods out of bounds
    try
    {
        std::cout << "array.set(1): ";
        array.set(1, 'b');
        std::cout << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "array.get(1): " << array.get(1) << std::endl
                  << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "array.set(-1): ";
        array.set(-1, 'b');
        std::cout << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "array.get(-1): " << array.get(-1) << std::endl
                  << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // test getting and setting with [] in bounds
    array[0] = 5;
    std::cout << "array[0]: " << array[0] << std::endl
              << std::endl;

    // test getting and setting with [] out of bounds
    try
    {
        array[1] = 6;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "array[1]: " << array[1] << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // test fill constructor
    Base_Array<char> filledArray(5, 'f');
    std::cout << "filled array: ";
    filledArray.print();
    std::cout << std::endl;

    // test copy constructor
    Base_Array<int> arrayCopy(array);
    std::cout << "arrayCopy[0]: " << arrayCopy[0] << std::endl;
    arrayCopy.set(0, 8);
    std::cout << "array[0]: " << array.get(0) << std::endl;
    std::cout << "arrayCopy[0]: " << arrayCopy.get(0) << std::endl
              << std::endl;

    // test destructor
    Base_Array<int> *arrPtr = new Base_Array<int>(5, 11);
    std::cout << "arrPtr[0]: " << arrPtr->get(0) << std::endl
              << std::endl;
    delete arrPtr;

    // overloaded assignment operator
    Base_Array<int> *assignmentOverloaded;
    assignmentOverloaded = &array;
    std::cout << "array[0]: " << array.get(0) << std::endl;
    std::cout << "assignmentOverloaded[0]: " << assignmentOverloaded->get(0) << std::endl
              << std::endl;

    assignmentOverloaded->set(0, 22);
    std::cout << "(after setting assignmentOverloaded[0])" << std::endl;
    std::cout << "array[0]: " << array.get(0) << std::endl;
    std::cout << "assignmentOverloaded[0]: " << assignmentOverloaded->get(0) << std::endl
              << std::endl;

    // test find
    Base_Array<char> testFind(5);
    testFind[0] = 'a';
    testFind[1] = 'b';
    testFind[2] = 'b';
    std::cout << "testFind.find('a'): " << testFind.find('a') << std::endl;
    std::cout << "testFind.find('b'): " << testFind.find('b') << std::endl;

    testFind[3] = 'c';
    testFind[4] = 'b';
    std::cout << "testFind.find('b', 3): " << testFind.find('b', 3) << std::endl
              << std::endl;

    std::cout << "testFind.find('d'): " << testFind.find('d') << std::endl;
    std::cout << "testFind.find('d', 3): " << testFind.find('d', 3) << std::endl
              << std::endl;

    // test == overloading
    Base_Array<char> equalityTest(1, 'a');
    Base_Array<char> *equalityTestPtr = &equalityTest;
    std::cout << "equality test: " << (equalityTest == *equalityTestPtr) << std::endl;
    std::cout << "equality test 2: " << (equalityTest == testFind) << std::endl;

    // test != overloading
    std::cout << "equality test: " << (equalityTest != *equalityTestPtr) << std::endl;
    std::cout << "equality test 2: " << (equalityTest != testFind) << std::endl
              << std::endl;

    // test fill
    Base_Array<int> testFill(5);
    testFill.fill(1);
    std::cout << "testFill: ";
    testFill.print();
    std::cout << std::endl
              << std::endl;
}

void Driver::testDynamicArray()
{
    std::cout << "DYNAMIC ARRAY TEST" << std::endl
              << std::endl;

    Array<int> arrayNull;
    std::cout << "driver.cpp and Array.cpp working" << std::endl
              << std::endl;

    // test array with length constructor
    // also test set and get methods in bounds
    Array<int> array(1);
    array.set(0, 3);
    std::cout << "array.get(0): " << array.get(0) << std::endl
              << std::endl;

    // test set and get methods out of bounds

    // test getting and setting with [] in bounds
    array[0] = 5;
    std::cout << "array[0]: " << array[0] << std::endl
              << std::endl;

    // test getting and setting with [] out of bounds

    // test fill constructor
    Array<char> filledArray(5, 'f');
    std::cout << "filled array: ";
    filledArray.print();
    std::cout << std::endl;

    // test copy constructor
    Array<int> arrayCopy(array);
    std::cout << "arrayCopy[0]: " << arrayCopy[0] << std::endl;
    arrayCopy.set(0, 8);
    std::cout << "array[0]: " << array.get(0) << std::endl;
    std::cout << "arrayCopy[0]: " << arrayCopy.get(0) << std::endl
              << std::endl;

    // test destructor
    Array<int> *arrPtr = new Array<int>(5, 11);
    std::cout << "arrPtr[0]: " << arrPtr->get(0) << std::endl
              << std::endl;
    delete arrPtr;

    // overloaded assignment operator
    Array<int> *assignmentOverloaded;
    assignmentOverloaded = &array;
    std::cout << "array[0]: " << array.get(0) << std::endl;
    std::cout << "assignmentOverloaded[0]: " << assignmentOverloaded->get(0) << std::endl
              << std::endl;

    assignmentOverloaded->set(0, 22);
    std::cout << "(after setting assignmentOverloaded[0])" << std::endl;
    std::cout << "array[0]: " << array.get(0) << std::endl;
    std::cout << "assignmentOverloaded[0]: " << assignmentOverloaded->get(0) << std::endl
              << std::endl;

    // test find
    Array<char> testFind(5);
    testFind[0] = 'a';
    testFind[1] = 'b';
    testFind[2] = 'b';
    std::cout << "testFind.find('a'): " << testFind.find('a') << std::endl;
    std::cout << "testFind.find('b'): " << testFind.find('b') << std::endl;

    testFind[3] = 'c';
    testFind[4] = 'b';
    std::cout << "testFind.find('b', 3): " << testFind.find('b', 3) << std::endl
              << std::endl;

    std::cout << "testFind.find('d'): " << testFind.find('d') << std::endl;
    std::cout << "testFind.find('d', 3): " << testFind.find('d', 3) << std::endl
              << std::endl;

    // test == overloading
    Array<char> equalityTest(1, 'a');
    Array<char> *equalityTestPtr = &equalityTest;
    std::cout << "equality test: " << (equalityTest == *equalityTestPtr) << std::endl;
    std::cout << "equality test 2: " << (equalityTest == testFind) << std::endl;

    // test != overloading
    std::cout << "equality test: " << (equalityTest != *equalityTestPtr) << std::endl;
    std::cout << "equality test 2: " << (equalityTest != testFind) << std::endl
              << std::endl;
}

void Driver::testFixedArray()
{
    std::cout << "FIXED ARRAY TEST" << std::endl
              << std::endl;

    Fixed_Array<int, 0> fixedArrayNull;
    Fixed_Array<int, 5> emptyArrayWithLen;
    Fixed_Array<int, 5> emptyArrayWithLenCopy(emptyArrayWithLen);
    emptyArrayWithLen.print();
    emptyArrayWithLenCopy.print();

    std::cout << std::endl;

    emptyArrayWithLen[0] = 2;
    emptyArrayWithLen.print();
    emptyArrayWithLenCopy.print();

    std::cout << std::endl;

    // test destructor
    Fixed_Array<int, 6> *arrPtr = new Fixed_Array<int, 6>(8);
    arrPtr->print();
    delete arrPtr;
    std::cout << std::endl;

    std::cout << std::endl;
}

void Driver::testStack()
{
    std::cout << "STACK TEST" << std::endl
              << std::endl;

    Stack<int> stack;
    stack.push(5);
    std::cout << stack.top() << std::endl;
    stack.push(7);
    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.top() << std::endl;
    stack.pop();
    // std::cout << stack.top() << std::endl;

    std::cout << std::endl;

    stack.push(1);
    std::cout << stack.top() << std::endl;
    stack.push(2);
    std::cout << stack.top() << std::endl
              << std::endl;

    Stack<int> stackAssignment = stack;
    std::cout << "assignment top: ";
    std::cout << stackAssignment.top() << std::endl
              << std::endl;

    Stack<int> stackCopy(stack);
    std::cout << stackCopy.top() << std::endl
              << std::endl;

    stack.clear();
    std::cout << stack.size() << std::endl
              << std::endl;
}

void Driver::testQueue()
{
    std::cout << "QUEUE TEST" << std::endl
              << std::endl;

    Queue<int> queue;
    queue.enqueue(1);

    std::cout << queue.front() << std::endl;
    std::cout << queue.back() << std::endl
              << std::endl;

    queue.enqueue(5);
    queue.enqueue(9);
    std::cout << "size " << queue.size() << std::endl;
    std::cout << "front " << queue.front() << std::endl;
    std::cout << "back " << queue.back() << std::endl
              << std::endl;

    queue.dequeue();
    std::cout << "size " << queue.size() << std::endl;
    std::cout << "front " << queue.front() << std::endl;
    std::cout << "back " << queue.back() << std::endl
              << std::endl;

    queue.dequeue();
    queue.dequeue();
    std::cout << "size " << queue.size() << std::endl
              << std::endl;
    // std::cout << queue.front() << std::endl;

    queue.enqueue(3);
    queue.enqueue(4);

    Queue<int> queueCopy(queue);
    std::cout << "queueCopy front " << queueCopy.front() << std::endl;
    std::cout << "queueCopy back " << queueCopy.back() << std::endl
              << std::endl;

    Queue<int> queueAssingment = queue;
    std::cout << "queueAssingment front " << queueCopy.front() << std::endl;
    std::cout << "queueAssingment back " << queueCopy.back() << std::endl
              << std::endl;

    queue.clear();
    std::cout << "queue size after clear " << queue.size() << std::endl;
    // queue.dequeue();
    std::cout << "queue is empty " << queue.is_empty() << std::endl
              << std::endl;

    Queue<int> *qPtr = new Queue<int>;
    qPtr->enqueue(8);
    std::cout << "qPtr front " << qPtr->front() << std::endl;
    delete qPtr;
}
