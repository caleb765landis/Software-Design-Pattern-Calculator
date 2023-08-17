// Queue.inl

//
// size
//
template <typename T>
inline size_t Queue<T>::size(void) const
{
    return this->cur_size;
} // end size

//
// front
//
template <typename T>
inline T Queue<T>::front(void) const
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        return this->data_[this->front_];
    } // end if
} // end front

//
// back
//
template <typename T>
inline T Queue<T>::back(void) const
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        return this->data_.get(this->back_);
    } // end if
} // end back

//
// is_empty
//
template <typename T>
inline bool Queue<T>::is_empty(void) const
{
    if (this->cur_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    } // end if
} // end is_empty