#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Binary_heap 
{
private:
    vector<T> heap;
    void heapify_up(int index);
    void heapify_down(int index);

protected:
    void insert(const T& value);
    const T& get_min() const;
    void delete_min();

public:
    Binary_heap() {}
    bool is_empty() const; 
    int get_size() const;
};

template <class T>
void Binary_heap<T>::heapify_up(int index) 
{
    if (index == 0) {return;}

    int parent_index = (index - 1) / 2;
    if (heap[parent_index] > heap[index]) 
    {
        swap(heap[parent_index], heap[index]);
        heapify_up(parent_index);
    }
}

template <class T>
void Binary_heap<T>::heapify_down(int index) 
{
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int smallest_index = index;

    if (left_child_index < heap.size() && heap[left_child_index] < heap[smallest_index]) 
    {
        smallest_index = left_child_index;
    }

    if (right_child_index < heap.size() && heap[right_child_index] < heap[smallest_index]) 
    {
        smallest_index = right_child_index;
    }

    if (smallest_index != index) 
    {
        swap(heap[index], heap[smallest_index]);
        heapify_down(smallest_index);
    }
}

template <class T>
bool Binary_heap<T>::is_empty() const 
{
    return heap.empty();
}

template <class T>
int Binary_heap<T>::get_size() const 
{
    return heap.size();
}

template <class T>
void Binary_heap<T>::insert(const T& value) 
{
    heap.push_back(value);
    heapify_up(heap.size() - 1);
}

template <class T>
const T& Binary_heap<T>::get_min() const 
{
    if (is_empty()) 
    {
        throw runtime_error("Heap is empty");
    }
    return heap[0];
}

template <class T>
void Binary_heap<T>::delete_min() 
{
    if (is_empty()) 
    {
        throw runtime_error("Heap is empty");
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(0);
}