#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge_el 
{
public:
    int source;
    int destination;
    int weight;

    Edge_el(int source_arg, int destination_arg, int weight_arg) : source(source_arg), destination(destination_arg), weight(weight_arg) {}
};

class Graph_edge_list 
{
    int num_vertices;
    vector<Edge_el> edge_list;

public:
    Graph_edge_list(int num_vertices_arg) : num_vertices(num_vertices_arg) {}

    void add_edge(int source, int destination, int weight);
    void prim_mst();
};

void Graph_edge_list::add_edge(int source, int destination, int weight)
{
    Edge_el edge(source, destination, weight);
    edge_list.push_back(edge);
}

void Graph_edge_list::prim_mst()
{
    vector<bool> visited(num_vertices, false);
    vector<int> parent(num_vertices, -1);
    vector<int> key(num_vertices, INT_MAX);

    Priority_queue_heap<int, int> my_pq;

    int start_vertex = 0;
    my_pq.enqueue(start_vertex, 0);
    key[start_vertex] = 0;

    while (!my_pq.is_empty())
    {
        int current_vertex = my_pq.front();
        my_pq.dequeue();
        visited[current_vertex] = true;

        for (const Edge_el& edge : edge_list)
        {
            if (edge.source == current_vertex || edge.destination == current_vertex)
            {
                int neighbor = (edge.source == current_vertex) ? edge.destination : edge.source;
                int weight = edge.weight;

                if (!visited[neighbor] && weight < key[neighbor])
                {
                    parent[neighbor] = current_vertex;
                    key[neighbor] = weight;
                    my_pq.enqueue(neighbor, weight);
                }
            }
        }
    }
}