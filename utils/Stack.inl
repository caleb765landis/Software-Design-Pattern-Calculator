// Stack.inl

//
// size
//
template <typename T>
inline size_t Stack<T>::size(void) const
{
    return this->data_.size();
} // end size

//
// top
//
template <typename T>
inline T Stack<T>::top(void) const
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        return this->data_.get(this->data_.size() - 1);
    } // end if
} // end top

//
// is_empty
//
template <typename T>
inline bool Stack<T>::is_empty(void) const
{
    if (this->data_.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    } // end if
} // end is_empty