#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge_al
{
public:
    int source;
    int destination;
    int weight;

    Edge_al(int source_arg, int destination_arg, int weight_arg) : source(source_arg), destination(destination_arg), weight(weight_arg) {}
};

class Graph_adj_list 
{
    int num_vertices;
    vector<vector<Edge_al>> adj_list;

public:
    Graph_adj_list(int num_vertices_arg) : num_vertices(num_vertices_arg), adj_list(num_vertices_arg) {}

    void add_edge(int source, int destination, int weight);
    void prim_mst();
};

void Graph_adj_list::add_edge(int source, int destination, int weight)
{
    Edge_al edge(source, destination, weight);
    adj_list[source].push_back(edge);

    Edge_al reverseEdge(destination, source, weight);
    adj_list[destination].push_back(reverseEdge);
}

void Graph_adj_list::prim_mst()
{
    vector<bool> visited(num_vertices, false);
    vector<int> parent(num_vertices, -1);
    vector<int> key(num_vertices, INT_MAX);

    Priority_queue_heap<int,int> my_pq;

    int start_vertex = 0;
    my_pq.enqueue(start_vertex, 0);
    key[start_vertex] = 0;

    while (!my_pq.is_empty())
    {
        int courrent_vertex = my_pq.front();
        my_pq.dequeue();
        visited[courrent_vertex] = true;

        for (const Edge_al& edge : adj_list[courrent_vertex])
        {
            int neighbor = edge.destination;
            int weight = edge.weight;

            if (!visited[neighbor] && weight < key[neighbor])
            {
                parent[neighbor] = courrent_vertex;
                key[neighbor] = weight;
                my_pq.enqueue(neighbor, weight);
            }   
        }
    }
}