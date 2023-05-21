#include <iostream>
#include <vector>
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

    int start_vertex = 0;
    key[start_vertex] = 0;

    for (size_t i = 0; i < num_vertices; i++)
    {
        int min_key = INT_MAX;
        int min_index = -1;
        for (size_t j = 0; j < num_vertices; j++)
        {
            if (!visited[j] && key[j] < min_key)
            {
                min_key = key[j];
                min_index = j;
            }
        }

        visited[min_index] = true;

        for (size_t k = 0; k < num_vertices; k++)
        {
            if (!visited[k] && adj_matrix[min_index][k] != 0 && adj_matrix[min_index][k] < key[k])
            {
                parent[k] = min_index;
                key[k] = adj_matrix[min_index][k];
            }
        }
    }
    cout << "Minimum spanning tree: " << endl;
    for (size_t i = 1; i < num_vertices; i++)
    {
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }
}