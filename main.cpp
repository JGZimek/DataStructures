#include <iostream>
#include "Priority Queue/Priority_Queue_List.cpp"
using namespace std;

int main()
{
    Priority_queue<int, int> my_pq;
    my_pq.enqueue(5,3);
    my_pq.enqueue(5,5);
    my_pq.enqueue(50,1);
    my_pq.enqueue(20,1);
    cout << my_pq.get_size() << endl;
    my_pq.dequeue();
    cout << my_pq.front() << endl;
    
    return 0;
}