// Fixed_Array.cpp

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void)
{
    this->data_ = new T[N];
    this->cur_size_ = N;
    this->max_size_ = N;
} // end Fixed_Array (void)

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N> &arr)
{
    this->data_ = new T[N];
    this->cur_size_ = N;
    this->max_size_ = N;

    for (int i = 0; i < N; i++)
    {
        this->data_[i] = arr.data_[i];
    } // end for
} // end copy constructor

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(T fill)
{
    this->data_ = new T[N];
    this->cur_size_ = N;
    this->max_size_ = N;

    for (int i = 0; i < N; i++)
    {
        this->data_[i] = fill;
    } // end for
} // end fill constructor

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::~Fixed_Array(void)
{
} // end destructor