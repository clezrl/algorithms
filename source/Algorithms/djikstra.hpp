/** Djikstra's Shortest Path
 * Finding the shortest path through a graph.
 *
 * The function takes the initial graph, and starting vertex.
 * It then constructs the minimum spanning tree to all vertices in the graph.
 * Return the resulting minimum spanning tree.
 */

#include "../Graphs/Graph.hpp"
#include "../String/String.hpp"
#include "../Queue/Queue.hpp"

Graph djikstras(Graph& G, int vertex) {
    bool marked[G.node_count()];
    int cost[G.node_count()];
    int path[G.node_count()];
    Queue queue;

    for (int i = 0; i < G.node_count(); ++i) {
        marked[i] = false;
        cost[i] = INT_MAX;
        path[i] = -1;
    }

    cost[vertex] = 0;
    marked[vertex] = true;
    queue.push(vertex);
    std::vector<int> neighbors;

    while (!queue.empty()) {
        int current = queue.pop();
        neighbors = G.neighbors(current);
        for (int i = 0; i < neighbors.size(); i++) {
            int u = neighbors[i];
            int weight = G.weight(current, u);
            if (marked[u]) {
                if (cost[u] > cost[current] + weight) {
                    cost[u] = cost[current] + weight;
                    path[u] = current;
                }
            } else {
                marked[u] = true;
                cost[u] = cost[current] + weight;
                path[u] = current;
                queue.push(u);
            }
        }
    }
    Graph g(G.node_count());
    for (int i = 0; i < G.node_count(); i++) {
        int from = path[i];
        if (from >= 0) {
            int weight = G.weight(from, i);
            g.add_edge(from, i, weight);
        }
    }

    return g;
}
