#ifndef QUEUE_H_
#define QUEUE_H_

#define DEFAULT_QUEUE 32

template<class T>
class Queue {
    private:
    T *m_data;
    int m_maxSize;// powers of 2
    int m_currSize;
    // data section

    public:
    void pushBack(const T&);
    T& front();
    void popFront();
    int size() const;
    //-----
    Queue();
    Queue(const Queue&);
    Queue& operator=(const Queue&);
    ~Queue();

    class Iterator {

        const Queue& m_q;
        int m_index;
        explicit Iterator(const Queue& q, int index);

        public:
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator&) const;
        bool operator<(const Iterator&) const;
        T& operator*();

        class InvalidOperation {};

        friend class Queue;
    };
    class ConstIterator {
        const Queue& m_q;
        int m_index;
        explicit ConstIterator(const Queue<T>& q, int index);

        public:
        // ConstIterator(const ConstIterator&) = default;
        // ConstIterator& operator=(const ConstIterator&) = default;
        // ~ConstIterator() = 

        ConstIterator& operator++();
        ConstIterator operator++(int); // probably not very needed but I'll keep for now
        bool operator!=(const ConstIterator&) const;
        bool operator<(const ConstIterator&) const;
        T operator*() const;
        class InvalidOperation {};
        friend class Queue;
    };
    class EmptyQueue {};

    ConstIterator begin() const;
    ConstIterator end() const;
    Iterator begin();
    Iterator end();

    template <class S>
    friend Queue<S> filter(Queue<S> queue, bool (*predict)(S data))
    {
        Queue<S> temp = queue;
        int j = 0;
        for(int i = 0; i < queue.m_currSize; ++i){
            if(predict(queue.m_data[i])){
                temp.m_data[j] = queue.m_data[i];
                ++j;
            }
        }
        temp.m_currSize = j;
        return temp;
    }

    template <class S>
    friend void transform(Queue<S>& queue, void (*operation)(S& data));
};

//_____________-Implementin Queue Section-__________________

template<class T>
Queue<T>::Queue() : m_data(new T[DEFAULT_QUEUE]), m_maxSize(DEFAULT_QUEUE), m_currSize(0){}

template<class T>
Queue<T>::Queue(const Queue& queue) : m_data(new T[queue.m_maxSize]), 
                m_maxSize(queue.m_maxSize), m_currSize(queue.m_currSize) 
{
    for(int i = 0; i < m_currSize; ++i){
        m_data[i] = queue.m_data[i]; // T needs to support operator=
    }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& queue)
{
    T* temp = new T[queue.m_maxSize];
    for(int i = 0; i < queue.m_currSize; ++i){
        temp[i] = queue.m_data[i];
    }
    m_currSize = queue.m_currSize;
    m_maxSize = queue.m_maxSize;

    delete[] m_data;
    m_data = temp;
    return *this;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] m_data;
}

template <class T>
void Queue<T>::pushBack(const T &node)
{
    // Do we need to alocate new memory space first?
    if(m_currSize+1 <= m_maxSize/2){
        m_data[m_currSize] = node;
        m_currSize++;
        return;
    }
    T* temp = new T[m_maxSize*2];
    for(int i = 0; i < m_currSize; ++i){
        temp[i] = m_data[i];
    }
    temp[m_currSize] = node;
    delete[] m_data;
    m_data = temp;
    m_maxSize *= 2;
    m_currSize +=1;
}

template <class T>
T& Queue<T>::front()
{
    if(m_currSize == 0){
        throw (Queue::EmptyQueue()); // can't build the object
    }
    return m_data[0];
}

template <class T>
void Queue<T>::popFront()
{
    if(m_currSize == 0) return;

    if(m_currSize-1 >= m_maxSize/4){
        for(int i = 1; i < m_currSize; ++i){
            m_data[i-1] = m_data[i];
        }
        --m_currSize;
        return;
    }

    T* temp = new T[m_maxSize/2];
    for(int i = 1; i < m_currSize; ++i){
        temp[i-1] = m_data[i];
    }
    delete[] m_data;
    m_data = temp;
    --m_currSize;
    m_maxSize /= 2;
}

template<class T>
int Queue<T>::size() const
{
    return m_currSize;
}

template <class S>
void transform(Queue<S>& queue, void (*operation)(S& data))
{
    for(int i = 0; i < queue.m_currSize; ++i){
        operation(queue.m_data[i]);
    }
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Queue::Iterator(*this, 0);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Queue::Iterator(*this, m_currSize);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return Queue::ConstIterator(*this, 0);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return Queue::ConstIterator(*this, m_currSize);
}

//___________-Implementing Iterator Section-________________

template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>& q, int index) : m_q(q), m_index(index) {}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(m_index == (m_q.size())){
        throw (Queue<T>::Iterator::InvalidOperation());
    }
    ++(this->m_index);
    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
    if(m_index == (m_q.size())){
        throw (Queue<T>::Iterator::InvalidOperation());
    }
    Iterator resault = *this;
    ++*this;
    return resault;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator& it) const
{
    // asserting it ant *this are iterators of the same Queue
    return m_index != it.m_index ? true : false;
}

template <class T>
bool Queue<T>::Iterator::operator<(const Queue<T>::Iterator& it) const
{
    return (m_index < it.m_index);
}

//__-None member functions for Iterator-__
template <class T>
bool operator==(typename Queue<T>::Iterator& it1, typename Queue<T>::Iterator& it2)
{
    if(it1 == it2)
        return true;
    return false;
}

template <class T>
bool operator<=(const typename Queue<T>::Iterator& it1, const typename Queue<T>::Iterator& it2)
{
    return !(it2 < it1);
}

template <class T>
T& Queue<T>::Iterator::operator*()
{
    return m_q.m_data[m_index];
}

//_________-Implementing constIterator Section-_____________

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>& queue, int index) : m_q(queue), m_index(index) {}

// template <class T>
// Queue<T>::ConstIterator::ConstIterator(const Queue<T>::ConstIterator& cit) : m_q(cit.m_q), {}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if(m_index == (m_q.size())){
        throw (Queue<T>::ConstIterator::InvalidOperation());
    }
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{
    if(m_index == (m_q.size())){
        throw (Queue<T>::ConstIterator::InvalidOperation());
    }
    Queue<T>::ConstIterator resault = *this;
    ++*this;
    return resault;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const Queue<T>::ConstIterator& cit) const
{
    return m_index != cit.m_index ? true : false;
}

template <class T>
bool operator==(const typename Queue<T>::constIterator& cit1, const typename Queue<T>::constIterator& cit2)
{
    return cit1 == cit2 ? true : false;
}

template <class T>
bool Queue<T>::ConstIterator::operator<(const Queue<T>::ConstIterator& cit) const
{
    return m_index < cit.m_index ? true : false;
}

template <class T>
bool operator<=(const typename Queue<T>::constIterator& cit1, const typename Queue<T>::constIterator& cit2)
{
    return cit2 < cit1 ? false : true;
}

template <class T>
T Queue<T>::ConstIterator::operator*() const
{
    return m_q.m_data[m_index];
}

#endif