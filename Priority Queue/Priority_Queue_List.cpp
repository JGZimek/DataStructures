#include <iostream>
#include <memory>
#include "../Linked List/Linked_list.cpp"
using namespace std;

template <class T, class P>
class Priority_queue : public Linked_list<T>
{
    struct Node : public Linked_list<T>::Node
    {
        P priority;

        Node(const T& data_arg, const P& priority_arg) : Linked_list<T>::Node(data_arg), priority(priority_arg) {}
    };

public:
    void enqueue(const T& value, const P& priority);
    void dequeue();
    T& front() const;
};

template <class T, class P>
void Priority_queue<T,P>::enqueue(const T& value, const P& priority)
{
    shared_ptr<Node> new_node = make_shared<Node>(value, priority);

    if (this -> is_empty() || priority >= static_pointer_cast<Node>(this -> head) -> priority)
    {
        this -> insert_head(value);
    }
    else if (priority < static_pointer_cast<Node>(this -> tail) -> priority)
    {
        this -> insert_tail(value);
    }
    else
    {
        shared_ptr<Node> current_node = static_pointer_cast<Node>(this -> head);
        while (current_node -> next && priority >= static_pointer_cast<Node>(current_node -> next) -> priority)
        {
            current_node = static_pointer_cast<Node>(current_node -> next);
        }

        new_node -> next = current_node -> next;
        new_node -> prev = current_node;
        current_node -> next = new_node;

        if (new_node -> next)
        {
            (new_node -> next) -> prev = new_node;
        }
        else
        {
            this -> tail = new_node;
        }
        this -> size++;        
    }
}

template <class T, class P>
void Priority_queue<T,P>::dequeue()
{
    if (this -> is_empty())
    {
        throw runtime_error("Queue is empty\n");
    }
    this -> remove_head();
}

template <class T, class P>
T& Priority_queue<T,P>::front() const
{
    if (this -> is_empty())
    {
        throw runtime_error("Queue is empty\n");
    }
    return this -> get_head();    
}
