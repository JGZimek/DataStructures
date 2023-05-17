#include <iostream>
#include <memory>
using namespace std;

template <class T>
class Linked_list
{
protected:
    struct Node
    {
        T data;
        shared_ptr<Node> next;
        shared_ptr<Node> prev;

        Node(const T& data_arg) : data(data_arg), next(nullptr), prev(nullptr) {}
    };

    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    size_t size;

protected:
    Linked_list() : head(nullptr), tail(nullptr), size(0) {}

    void insert_head(const T& value);
    void insert_tail(const T& value);
    void remove_head();
    void remove_tail();
    T& get_head() const;
    T& get_tail() const;

public:
    size_t get_size() const;
    bool is_empty() const;
};

template <class T>
size_t Linked_list<T>::get_size() const
{
    return size;
}

template <class T>
bool Linked_list<T>::is_empty() const
{
    return size == 0;
}

template <class T>
void Linked_list<T>::insert_head(const T& value)
{
    shared_ptr<Node> new_node = make_shared<Node>(value);

    if (!head)
    {
        tail = new_node;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
    }
    head = new_node;
    size++;
}

template <class T>
void Linked_list<T>::insert_tail(const T& value)
{
    shared_ptr<Node> new_node = make_shared<Node>(value);
    if (!tail)
    {
        head = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    tail = new_node;
    size++;    
}

template <class T>
void Linked_list<T>::remove_head()
{
    if (!head)
    {
        throw runtime_error("List is empty\n");
    }
    head = head->next;
    if (head)
    {
        head->prev.reset();
    }
    else
    {
        tail.reset();
    }
    size--;    
}

template <class T>
void Linked_list<T>::remove_tail()
{
    if (!tail)
    {
        throw runtime_error("List is empty\n");
    }
    tail = tail->prev;
    if (tail)
    {
        tail->next.reset();
    }
    else
    {
        head.reset();
    }
    size--; 
}

template <class T>
T& Linked_list<T>::get_head() const
{
    if (!head)
    {
        throw runtime_error("List is empty\n");
    }
    return head->data;
}

template <class T>
T& Linked_list<T>::get_tail() const
{
    if (!tail)
    {
        throw runtime_error("List is empty\n");
    }
    return tail->data;
}
