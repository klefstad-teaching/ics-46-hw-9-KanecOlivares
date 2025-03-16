#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int graph_sz = G.numVertices;
    vector<int> dist(graph_sz, INF);
    vector<int> visited(graph_sz, false);
    previous.assign(G.numVertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;  // Mark the node as processed

        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            // Relax the edge if a shorter path to v is found
            if (dist_u + weight < dist[v]) {
                dist[v] = dist_u + weight;
                previous[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> result;
    if (distances[destination] == INF)
        return result;
    for (int at = destination; at != -1; at = previous[at])
        result.push_back(at);
    reverse(result.begin(), result.end());
    return result;
}

void print_path(const vector<int>& v, int total){
    int vector_sz = v.size();
    for (int i = 0; i < vector_sz && i < total; ++i)
        cout << v[i] << " "; 
}