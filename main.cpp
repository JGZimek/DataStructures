#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include "Priority Queue/Priority_queue_heap.cpp"
#include "Graph Prim/Adj_list.cpp"
#include "Graph Prim/Adj_matrix.cpp"
#include "Graph Prim/Edge_list.cpp"
using namespace std;
using namespace std::chrono;

void generate_random_graph(Graph_adj_list& graph, int num_vertices, double density)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_weight(1, 100);

    int num_edges = static_cast<int>(density * num_vertices * (num_vertices - 1) / 200);

    for (int i = 0; i < num_edges; i++)
    {
        int source = rand() % num_vertices;
        int destination = rand() % num_vertices;
        int weight = dis_weight(gen);

        graph.add_edge(source, destination, weight);
    }
}

void generate_random_graph(Graph_adj_matrix& graph, int num_vertices, double density)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_weight(1, 100);

    int num_edges = static_cast<int>(density * num_vertices * (num_vertices - 1) / 200);

    for (int i = 0; i < num_edges; i++)
    {
        int source = rand() % num_vertices;
        int destination = rand() % num_vertices;
        int weight = dis_weight(gen);

        graph.add_edge(source, destination, weight);
    }
}

void generate_random_graph(Graph_edge_list& graph, int num_vertices, double density)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_weight(1, 100);

    int num_edges = static_cast<int>(density * num_vertices * (num_vertices - 1) / 200);

    for (int i = 0; i < num_edges; i++)
    {
        int source = rand() % num_vertices;
        int destination = rand() % num_vertices;
        int weight = dis_weight(gen);

        graph.add_edge(source, destination, weight);
    }
}

void run_tests_adj_list(int num_vertices, double density)
{
    Graph_adj_list graph(num_vertices);

    generate_random_graph(graph, num_vertices, density);

    auto start = high_resolution_clock::now();

    graph.prim_mst();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Execution time (adjacency list) for " << num_vertices << " vertices with " << density << "% density: " << duration.count() << " ms" << endl;
}

void run_tests_adj_matrix(int num_vertices, double density)
{
    Graph_adj_matrix graph(num_vertices);

    generate_random_graph(graph, num_vertices, density);

    auto start = high_resolution_clock::now();

    graph.prim_mst();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Execution time (adjacency matrix) for " << num_vertices << " vertices with " << density << "% density: " << duration.count() << " ms" << endl;
}

void run_tests_edge_list(int num_vertices, double density)
{
    Graph_edge_list graph(num_vertices);

    generate_random_graph(graph, num_vertices, density);

    auto start = high_resolution_clock::now();

    graph.prim_mst();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Execution time (edge list) for " << num_vertices << " vertices with " << density << "% density: " << duration.count() << " ms" << endl;
}

int main()
{
    vector<int> num_vertices_list = {50, 100, 400, 500, 1000, 1500, 3000};
    vector<double> densities = {10.0, 30.0, 50.0, 100.0}; 

    for (int num_vertices : num_vertices_list)
    {
        for (double density : densities)
        {
            run_tests_adj_list(num_vertices, density);
            run_tests_adj_matrix(num_vertices, density);
            run_tests_edge_list(num_vertices, density);
            
            cout << endl;
        }
    }

    return 0;
}
