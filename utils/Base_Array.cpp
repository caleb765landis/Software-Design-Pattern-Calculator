// Base_Array.cpp

//
// Base_Array
//
template <typename T>
Base_Array<T>::Base_Array(void)
    : data_(nullptr),
      cur_size_(0),
      max_size_(0)
{
} // end Base_Array (void)

//
// Base_Array (size_t)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length)
    : data_(new T[length]),
      cur_size_(length),
      max_size_(length)
{
} // end Base_Array (size_t length)

//
// Base_Array (size_t, T)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill)
    : data_(new T[length]),
      cur_size_(length),
      max_size_(length)
{
    for (size_t i = 0; i < length; i++)
    {
        this->data_[i] = fill;
    } // end for
} // end Base_Array (size_t length, T fill)

//
// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array<T>::Base_Array(const Base_Array &base_array)
    : data_(new T[base_array.size()]),
      cur_size_(base_array.size()),
      max_size_(base_array.max_size())
{
    for (int i = 0; i < base_array.size(); i++)
    {
        this->data_[i] = base_array.data_[i];
    } // end for
} // end Base_Array (const Base_Array & base_array)

//
// ~Base_Array
//
template <typename T>
Base_Array<T>::~Base_Array(void)
{
    delete[] this->data_;
} // end destructor

//
// operator =
//
template <typename T>
const Base_Array<T> &Base_Array<T>::operator=(const Base_Array &rhs)
{
    if (this != &rhs)
    {
        this->cur_size_ = rhs.cur_size_;
        this->max_size_ = rhs.max_size_;

        for (int i = 0; i < this->cur_size_; ++i)
        {
            this->data_[i] = rhs.data_[i];
        } // end for
    }     // end if

    return *this;
} // end = overload

//
// operator []
//
template <typename T>
T &Base_Array<T>::operator[](size_t index)
{
    if (index >= this->cur_size_ || index < 0)
    {
        throw std::out_of_range("Error: Index out of range.");
    }
    else
    {
        return this->data_[index];
    } // end if
} // end [] overload

//
// operator []
//
template <typename T>
const T &Base_Array<T>::operator[](size_t index) const
{
    if (index >= this->cur_size_ || index < 0)
    {
        throw std::out_of_range("Error: Index out of range.");
    }
    else
    {
        return this->data_[index];
    } // end if
} // end const [] overload

//
// get
//
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    if (index >= this->cur_size_ || index < 0)
    {
        throw std::out_of_range("Error: Index out of range.");
    }
    else
    {
        return this->data_[index];
    } // end if
} // end get

//
// set
//
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    if (index >= this->cur_size_ || index < 0)
    {
        throw std::out_of_range("Error: Index set out of range.");
    }
    else
    {
        this->data_[index] = value;
    } // end if
} // end set

//
// find (T)
//
template <typename T>
int Base_Array<T>::find(T value) const
{
    int foundIndex = -1;

    for (int i = 0; i < this->cur_size_; i++)
    {
        if (this->data_[i] == value)
        {
            foundIndex = i;
            return foundIndex;
        } // end if
    }     // end for

    return foundIndex;
} // end find

//
// find (T, size_t)
//
template <typename T>
int Base_Array<T>::find(T val, size_t start) const
{
    int foundIndex = -1;

    for (int i = start; i < this->cur_size_; i++)
    {
        if (this->data_[i] == val)
        {
            foundIndex = i;
            return foundIndex;
        } // end if
    }     // end for

    return foundIndex;
} // end find with start

//
// operator ==
//
template <typename T>
bool Base_Array<T>::operator==(const Base_Array &rhs) const
{
    if (this->data_ != rhs.data_)
    {
        if (this->data_ == rhs.data_)
        {
            return true;
        }
        else
        {
            return false;
        } // end if
    }
    else
    {
        return true;
    } // end if
} // end == overload

//
// operator !=
//
template <typename T>
bool Base_Array<T>::operator!=(const Base_Array &rhs) const
{
    if (this->data_ == rhs.data_)
    {
        return false;
    }
    else
    {
        return true;
    } // end if
} // end != overload

//
// fill
//
template <typename T>
void Base_Array<T>::fill(T value)
{
    for (int i = 0; i < this->cur_size_; i++)
    {
        this->data_[i] = value;
    } // end for
} // end fill

//
// print
//
template <typename T>
void Base_Array<T>::print()
{
    for (int i = 0; i < (this->cur_size_ - 1); i++)
    {
        std::cout << this->data_[i] << ", ";
    } // end for
    std::cout << this->data_[this->cur_size_ - 1] << std::endl;
}
