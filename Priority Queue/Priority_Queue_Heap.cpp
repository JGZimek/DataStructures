#include <iostream>
#include "Binary_heap.cpp"
using namespace std;

template <class T, class P>
class Priority_queue_heap : public Binary_heap<T, P> 
{
public:
    void enqueue(const T& value, int priority);
    const T& front() const;
    void dequeue();
};

template <class T, class P>
void Priority_queue_heap<T, P>::enqueue(const T& value, int priority) 
{
    this-> insert(value, priority);
}

template <class T, class P>
const T& Priority_queue_heap<T, P>::front() const 
{
    return this-> get_min();
}

template <class T, class P>
void Priority_queue_heap<T, P>::dequeue() 
{
    this-> delete_min();
}
