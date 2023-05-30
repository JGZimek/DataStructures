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
    static int edge_counter = 0;

    inc_matrix[source][edge_counter] = weight;
    inc_matrix[destination][edge_counter] = weight;

    edge_counter++;
}

void Graph_inc_matrix::prim_mst()
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

        for (int edge = 0; edge < num_edges; edge++)
        {
            int neighbor = -1;
            int weight = 0;

            if (inc_matrix[current_vertex][edge] != 0)
            {
                for (int i = 0; i < num_vertices; i++)
                {
                    if (inc_matrix[i][edge] != 0 && i != current_vertex)
                    {
                        neighbor = i;
                        weight = inc_matrix[i][edge];
                        break;
                    }
                }
            }

            if (neighbor != -1 && !visited[neighbor] && weight < key[neighbor])
            {
                parent[neighbor] = current_vertex;
                key[neighbor] = weight;
                my_pq.enqueue(neighbor, weight);
            }
        }
    }
}
