#include <iostream>
#include <vector>
using namespace std;

class Graph_inc_matrix
{
    int num_vertices;
    int num_edges;
    vector<vector<int>> inc_matrix;

public:
    Graph_inc_matrix(int num_vertices_arg, int num_edges_arg) : num_vertices(num_vertices_arg), num_edges(num_edges_arg), inc_matrix(num_vertices_arg, vector<int>(num_edges_arg, 0)) {}

    void add_edge(int source, int destination, int weight);
    void prim_mst();
};

void Graph_inc_matrix::add_edge(int source, int destination, int weight)
{
    static int edge_count = 0;
    inc_matrix[source][edge_count] = weight;
    inc_matrix[destination][edge_count] = weight;
    edge_count++;
}

void Graph_inc_matrix::prim_mst()
{
    vector<bool> visited(num_vertices, false);
    vector<int> parent(num_vertices, -1);
    vector<int> key(num_vertices, INT_MAX);

    int start_vertex = 0;
    key[start_vertex] = 0;

    for (int i = 0; i < num_vertices - 1; i++)
    {
        int min_key = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < num_vertices; j++)
        {
            if (!visited[j] && key[j] < min_key)
            {
                min_key = key[j];
                min_index = j;
            }
        }

        visited[min_index] = true;

        for (int k = 0; k < num_edges; k++)
        {
            int source = -1;
            int destination = -1;
            bool found_source = false;
            bool found_destination = false;

            for (int v = 0; v < num_vertices; v++)
            {
                if (inc_matrix[v][k] != 0)
                {
                    if (source == -1)
                    {
                        source = v;
                        found_source = true;
                    }
                    else
                    {
                        destination = v;
                        found_destination = true;
                        break;
                    }
                }
            }

            if (found_source && found_destination)
            {
                if (!visited[source] && inc_matrix[source][k] < key[source])
                {
                    parent[source] = destination;
                    key[source] = inc_matrix[source][k];
                }
                else if (!visited[destination] && inc_matrix[destination][k] < key[destination])
                {
                    parent[destination] = source;
                    key[destination] = inc_matrix[destination][k];
                }
            }
        }
    }

    cout << "Minimum spanning tree: " << endl;
    for (int i = 1; i < num_vertices; i++)
    {
        cout << "Edge: " << parent[i] << " - " << i << endl;
    }
}