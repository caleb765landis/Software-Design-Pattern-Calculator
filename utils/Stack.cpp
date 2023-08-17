// Stack.cpp

//
// Stack
//
template <typename T>
Stack<T>::Stack(void)
    : data_(Array<T>(0))
{
} // end constructor

//
// Stack
//
template <typename T>
Stack<T>::Stack(const Stack &stack)
    : data_(Array<T>(stack.size()))
{
    for (int i = 0; i < stack.size(); i++)
    {
        this->data_.set(i, stack.data_.get(i));
    } // end for
} // end copy constructor

//
// ~Stack
//
template <typename T>
Stack<T>::~Stack(void)
{
} // end destructor

//
// push
//
template <typename T>
void Stack<T>::push(T element)
{
    // resize stack
    this->data_.resize(this->data_.size() + 1);

    // set top of stack to element
    this->data_.set(this->data_.size() - 1, element);
} // end push

//
// pop
//
template <typename T>
void Stack<T>::pop(void)
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        // resize stack
        this->data_.resize(this->data_.size() - 1);
    } // end if
} // end pop

//
// operator =
//
template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < rhs.size(); ++i)
        {
            this->data_.set(i, rhs.data_.get(i));
        } // end for
    }     // end if

    return *this;
} // end assignment operator overload

//
// clear
//
template <typename T>
void Stack<T>::clear(void)
{
    this->data_.resize(0);
} // end clear