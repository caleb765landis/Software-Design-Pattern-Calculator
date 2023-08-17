// Queue.cpp

//
// Queue
//
template <typename T>
Queue<T>::Queue(void)
    : data_(Array<T>(0))
{
    this->cur_size = 0;
    this->front_ = -1;
    this->back_ = -1;
} // end constructor

//
// Queue
//
template <typename T>
Queue<T>::Queue(const Queue &queue)
    : data_(Array<T>(queue.size()))
{
    this->cur_size = queue.size();
    this->front_ = queue.front();
    this->back_ = queue.back();

    for (int i = 0; i < queue.size(); i++)
    {
        this->data_.set(i, queue.data_.get(i));
    } // end for
} // end copy constructor

//
// ~Queue
//
template <typename T>
Queue<T>::~Queue(void)
{
} // end destructor

//
// push
//
template <typename T>
void Queue<T>::enqueue(T element)
{
    // resize queue
    this->data_.resize(this->data_.size() + 1);

    // enqueue element onto back of array
    this->data_.set(this->data_.size() - 1, element);

    // update current size
    this->cur_size++;

    // set position of last element
    this->back_++;

    if (this->front_ == -1)
    {
        this->front_++;
    }
} // end enqueue

//
// dequeue
//
template <typename T>
void Queue<T>::dequeue(void)
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        // decrease current size
        this->cur_size--;

        // if (this -> front_ == this -> back_) {
        //   this -> front_ = -1;
        //   this -> back_ = -1;
        // } else {
        this->front_++;
        //}
    } // end if
} // end dequeue

//
// operator =
//
template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < rhs->size(); ++i)
        {
            this->data_->set(i, rhs.data_->get(i));
        } // end for
    }     // end if

    return *this;
} // end assignment operator overload

//
// clear
//
template <typename T>
void Queue<T>::clear(void)
{
    this->data_.resize(0);
} // end clear
