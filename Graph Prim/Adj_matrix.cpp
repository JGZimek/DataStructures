#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph_adj_matrix
{
    int num_vertices;
    vector<vector<int>> adj_matrix;

public:
    Graph_adj_matrix(int num_vertices_arg) : num_vertices(num_vertices_arg), adj_matrix(num_vertices_arg, vector<int>(num_vertices_arg, 0)) {}

    void add_edge(int source, int destination, int weight);
    void prim_mst();
};

void Graph_adj_matrix::add_edge(int source, int destination, int weight)
{
    adj_matrix[source][destination] = weight;
    adj_matrix[destination][source] = weight;
}

void Graph_adj_matrix::prim_mst()
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

        for (int neighbor = 0; neighbor < num_vertices; neighbor++)
        {
            int weight = adj_matrix[current_vertex][neighbor];

            if (!visited[neighbor] && weight != 0 && weight < key[neighbor])
            {
                parent[neighbor] = current_vertex;
                key[neighbor] = weight;
                my_pq.enqueue(neighbor, weight);
            }
        }
    }
}
