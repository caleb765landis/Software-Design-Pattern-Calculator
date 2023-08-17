// Array.cpp

#include "Array.h"
#include <stdexcept> // for std::out_of_bounds exception
#include <iostream>

//
// Array
//
template <typename T>
Array<T>::Array(void)
{
    this->data_ = nullptr;
    this->cur_size_ = 0;
    this->max_size_ = 0;
} // end Array (void)

//
// Array (size_t)
//
template <typename T>
Array<T>::Array(size_t length)
{
    this->data_ = new T[length];
    this->cur_size_ = length;
    this->max_size_ = length;
} // end Array (size_t length)

//
// Array (size_t, T)
//
template <typename T>
Array<T>::Array(size_t length, T fill)
{
    this->data_ = new T[length];
    this->cur_size_ = length;
    this->max_size_ = length;

    for (size_t i = 0; i < length; i++)
    {
        this->data_[i] = fill;
    } // end for
} // end Array (size_t length, T fill)

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array &array)
{
    this->data_ = new T[array.size()];
    this->cur_size_ = array.size();
    this->max_size_ = array.max_size();

    for (int i = 0; i < array.size(); i++)
    {
        this->data_[i] = array.data_[i];
    } // end for
} // end Array (const Array & array)

//
// ~Array
//
template <typename T>
Array<T>::~Array(void)
{
} // end destructor

//
// operator =
//
template <typename T>
const Array<T> &Array<T>::operator=(const Array &rhs)
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
T &Array<T>::operator[](size_t index)
{
    try
    {
        if (index >= this->cur_size_ || index < 0)
        {
            throw std::out_of_range("Error: Index out of range.");
        }
        else
        {
            return this->data_[index];
        } // end if
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
        exit(0);
    } // end catch
} // end [] overload

//
// operator []
//
template <typename T>
const T &Array<T>::operator[](size_t index) const
{
    try
    {
        if (index >= this->cur_size_ || index < 0)
        {
            throw std::out_of_range("Error: Index out of range.");
        }
        else
        {
            return this->data_[index];
        } // end if
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
        exit(0);
    } // end catch
} // end const [] overload

//
// resize
//
template <typename T>
void Array<T>::resize(size_t new_size)
{
    if (new_size < this->cur_size_)
    {
        this->cur_size_ = new_size;
    }
    else if (new_size > this->cur_size_)
    {
        T *temp = new T[new_size];

        for (int i = 0; i < this->cur_size_; i++)
        {
            temp[i] = this->data_[i];
        } // end for

        this->cur_size_ = new_size;
        this->max_size_ = new_size;
        delete[] this->data_;
        this->data_ = temp;
    } // end if
} // end resize

//
// operator ==
//
template <typename T>
bool Array<T>::operator==(const Array &rhs) const
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
bool Array<T>::operator!=(const Array &rhs) const
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