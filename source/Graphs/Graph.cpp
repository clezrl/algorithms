#include "Graph.hpp"

Graph::Graph(unsigned int n) {
    if (n == 0) throw "Size must be greater than 0";
    for (int i = 0; i < n; ++i) {
        Node* node = new Node(0, std::vector<int>(n, 0));
        vertices.push_back(*node);
    }
}

Graph::~Graph() {
     vertices.clear();
}

unsigned int Graph::node_count() {
    return vertices.size();
}

unsigned int Graph::edge_count() {
    int count = 0;
    for (int i = 0; i < vertices.size(); ++i) {
        count += neighbors(i).size();
    }
    return count;
}

int Graph::get_value(unsigned int v) {
     return vertices[v].data;
}

void Graph::set_value(unsigned int v, int val) {
    vertices[v].data = val;
}

int Graph::weight(unsigned int v, unsigned int w) {
    return vertices[v].edges[w];
}

bool Graph::has_edge(unsigned int v, unsigned int w) {
    return vertices[v].edges[w] != 0;
}

void Graph::add_edge(unsigned int v, unsigned int w, int weight) {
    if (v == w) throw "No Self-Edges!";
    vertices[v].edges[w] = weight;
    vertices[w].edges[v] = weight;
}

void Graph::remove_edge(unsigned int v, unsigned int w) {
    if (!vertices[v].edges[w] && !vertices[w].edges[v]) throw "Edge does not exist!";
    vertices[v].edges[w] = 0;
    vertices[w].edges[v] = 0;
}

std::vector<int> Graph::neighbors(unsigned int v) {
    std::vector<int> neighbor;
    for (int i = 0; i < vertices[v].edges.size(); ++i) {
        if (vertices[v].edges[i] != 0) 
            neighbor.push_back(i);
    }
    return neighbor;
}

