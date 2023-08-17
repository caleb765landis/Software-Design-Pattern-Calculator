//==============================================================================
/**
 * @file       Queue.h
 *
 * Basic implementation of a queue template class for arbitrary elements of typename T.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include <exception>
#include <iostream>

template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the Queue is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception(void)
            : std::exception() {}
    };

    /// Default constructor.
    Queue(void);

    /// Copy constructor.
    Queue(const Queue &queue);

    /// Destructor.
    ~Queue(void);

    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue &operator=(const Queue &rhs);

    /**
     * Push a new \a element onto the queue. The element is inserted
     * after all the other elements in the list.
     *
     * @param[in]      element       Element to add to the list
     */
    void enqueue(T element);

    /**
     * Remove the front-most element from the queue.
     *
     * @exception      empty_exception    The queue is empty.
     */
    void dequeue(void);

    /**
     * Get the front-most element on the queue. If there are no elements
     * on the queue, then the queue is_empty exception is thrown.
     *
     * @return         Element at front of the queue.
     * @exception      empty_exception    The queue is empty
     */
    T front(void) const;

    /**
     * Get the last element on the queue. If there are no elements
     * on the queue, then the queue is_empty exception is thrown.
     *
     * @return         Element at back of the queue.
     * @exception      empty_exception    The queue is empty
     */
    T back(void) const;

    /**
     * Test if the queue is empty
     *
     * @retval         true          The queue is empty
     * @retval         false         The queue is not empty
     */
    bool is_empty(void) const;

    /**
     * Number of elements on the queue.
     *
     * @return         Size of the queue.
     */
    size_t size(void) const;

    /// Remove all elements from the queue.
    void clear(void);

private:
    // Pointer to the actual data
    Array<T> data_;

    size_t cur_size;
    size_t front_;
    size_t back_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif // defined _Queue_H_