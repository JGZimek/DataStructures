#include <iostream>
#include <vector>
using namespace std;

template <class T, class P>
class Binary_heap 
{
protected:
    struct Node 
    {
        T value;
        P priority;

        Node(const T& value_arg, const P& priority_arg) : value(value_arg), priority(priority_arg) {}
    };
    vector<Node> heap;

    void heapify_up(int index);
    void heapify_down(int index);
    void insert(const T& value, int priority);
    const T& get_min() const;
    void delete_min();

public:
    Binary_heap() {}
    bool is_empty() const;
    int get_size() const;
};

template <class T, class P>
void Binary_heap<T,P>::heapify_up(int index) 
{
    if (index == 0) {return;}

    int parent_index = (index - 1) / 2;
    if (heap[parent_index].priority > heap[index].priority) 
    {
        swap(heap[parent_index], heap[index]);
        heapify_up(parent_index);
    }
}

template <class T, class P>
void Binary_heap<T,P>::heapify_down(int index) 
{
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int smallest_index = index;

    if (left_child_index < heap.size() && heap[left_child_index].priority < heap[smallest_index].priority) 
    {
        smallest_index = left_child_index;
    }

    if (right_child_index < heap.size() && heap[right_child_index].priority < heap[smallest_index].priority) 
    {
        smallest_index = right_child_index;
    }

    if (smallest_index != index) 
    {
        swap(heap[index], heap[smallest_index]);
        heapify_down(smallest_index);
    }
}

template <class T, class P>
bool Binary_heap<T,P>::is_empty() const 
{
    return heap.empty();
}

template <class T, class P>
int Binary_heap<T,P>::get_size() const 
{
    return heap.size();
}

template <class T, class P>
void Binary_heap<T,P>::insert(const T& value, int priority) 
{
    Node new_node (value, priority);
    heap.push_back(new_node);
    heapify_up(heap.size() - 1);
}

template <class T, class P>
const T& Binary_heap<T,P>::get_min() const 
{
    if (is_empty()) 
    {
        throw runtime_error("Heap is empty");
    }
    return heap[0].value;
}

template <class T, class P>
void Binary_heap<T,P>::delete_min() 
{
    if (is_empty()) 
    {
        throw runtime_error("Heap is empty");
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(0);
}