#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int graph_sz = G.numVertices;
    vector<int> dist(graph_sz, INF);
    vector<int> visted(graph_sz, false);
    previous.assign(G.numVertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > dist[u])
            continue;
        visted[u] = true; 

        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v] && !visted[u]) {
                dist[v] = dist[u] + weight;
                previous[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> resuslt;
    if (distances[destination] == INF)
        return result;
    for (int at = destination; at != -1; at = previous[at])
        result.push_back(at);
    reverse(result.begin(), result.end());
    return result;
}

void print_path(const vector<int>& v, int total){
    int vector_sz = v.size();
    for (int i < 0; i < vector_sz && i < total; ++i)
        cout << vector[i] << " "; 
}