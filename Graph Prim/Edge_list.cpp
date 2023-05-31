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

    Edge_el(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

class Graph_edge_list 
{
    int num_vertices;
    vector<Edge_el> edges;

public:
    Graph_edge_list(int num_vertices_arg);
    void add_edge(int source, int destination, int weight);
    void prim_mst();
};

Graph_edge_list::Graph_edge_list(int num_vertices_arg) : num_vertices(num_vertices_arg) {}

void Graph_edge_list::add_edge(int source, int destination, int weight) 
{
    Edge_el edge(source, destination, weight);
    edges.push_back(edge);

    Edge_el reverseEdge(destination, source, weight);
    edges.push_back(reverseEdge);
}

void Graph_edge_list::prim_mst() 
{
    vector<bool> visited(num_vertices, false);
    vector<int> parent(num_vertices, -1);
    vector<int> key(num_vertices, INT_MAX);

    Priority_queue_heap<pair<int, int>, int> pq;

    int start_vertex = 0;
    pq.enqueue(make_pair(0, start_vertex), 0);
    key[start_vertex] = 0;

    while (!pq.is_empty()) 
    {
        pair<int, int> top = pq.front();
        pq.dequeue();

        int u = top.second;

        visited[u] = true;

        for (const auto& edge : edges) 
        {
            if (edge.source == u && !visited[edge.destination] && edge.weight < key[edge.destination]) 
            {
                parent[edge.destination] = u;
                key[edge.destination] = edge.weight;
                pq.enqueue(make_pair(key[edge.destination], edge.destination), key[edge.destination]);
            }
        }
    }
}