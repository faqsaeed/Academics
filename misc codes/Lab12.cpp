#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList; // Adjacency list (node, weight)

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v, int weight = 1) 
    {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // Comment for directed graphs
    }

    void BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto& neighbor : adjList[node]) 
        {
            if (!visited[neighbor.first]) 
            {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
}

void DFSUtil(int v, vector<bool>& visited) 
{
    visited[v] = true;
    cout << v << " ";

    for (auto& neighbor : adjList[v]) 
    {
        if (!visited[neighbor.first])
            DFSUtil(neighbor.first, visited);
        
    }
}

void DFS(int start) 
{
    vector<bool> visited(V, false);
    DFSUtil(start, visited);
}

vector<int> Dijkstra(int start) 
{
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
    bool hasCycleUtil(int v, vector<bool>& visited, int parent) {
    visited[v] = true;

    for (auto& neighbor : adjList[v]) {
        if (!visited[neighbor.first]) {
            if (hasCycleUtil(neighbor.first, visited, v)) {
                return true;
            }
        } else if (neighbor.first != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle() {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && hasCycleUtil(i, visited, -1)) {
            return true;
        }
    }

    return false;
}

int TSP() {
    vector<int> nodes(V);
    for (int i = 0; i < V; ++i) nodes[i] = i;

    int minCost = INT_MAX;

    do {
        int cost = 0;
        bool valid = true;

        for (int i = 0; i < V - 1; ++i) {
            auto it = find_if(adjList[nodes[i]].begin(), adjList[nodes[i]].end(),
                              [nodes, i](pair<int, int> p) { return p.first == nodes[i + 1]; });
            if (it != adjList[nodes[i]].end()) {
                cost += it->second;
            } else {
                valid = false;
                break;
            }
        }

        if (valid) {
            auto it = find_if(adjList[nodes[V - 1]].begin(), adjList[nodes[V - 1]].end(),
                              [nodes](pair<int, int> p) { return p.first == nodes[0]; });
            if (it != adjList[nodes[V - 1]].end()) {
                cost += it->second;
                minCost = min(minCost, cost);
            }
        }
    } while (next_permutation(nodes.begin(), nodes.end()));

    return minCost;
}
};

int main() {
    cout << "Testing BFS and DFS:" << endl;
    Graph g1(6);
    g1.addEdge(0, 1);
    g1.addEdge(0, 3);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(1, 5);
    g1.addEdge(2, 5);
    g1.addEdge(3, 5);

    cout << "BFS starting from node 0: ";
    g1.BFS(0);
    cout << endl;

    cout << "DFS starting from node 0: ";
    g1.DFS(0);
    cout << endl;

    // Test Dijkstra's 
    cout << "\nTesting Dijkstra's Algorithm:" << endl;
    Graph g2(6);
    g2.addEdge(0, 1, 1);
    g2.addEdge(0, 2, 4);
    g2.addEdge(1, 2, 2);
    g2.addEdge(1, 3, 6);
    g2.addEdge(2, 3, 3);
    g2.addEdge(3, 4, 1);
    g2.addEdge(4, 5, 2);

    vector<int> distances = g2.Dijkstra(0);
    cout << "Shortest paths from node 0: ";
    for (int dist : distances) {
        cout << dist << " ";
    }
    cout << endl;

    // Test Cycle Detection
    cout << "\nTesting Cycle Detection:" << endl;
    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1); // Creates a cycle

    cout << "Cycle in directed graph: " << (g3.hasCycle() ? "Yes" : "No") << endl;

    Graph g4(5);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0); // Creates a cycle
    g4.addEdge(1, 3);
    g4.addEdge(3, 4);

    cout << "Cycle in undirected graph: " << (g4.hasCycle() ? "Yes" : "No") << endl;

    // Test TSP
    cout << "\nTesting Traveling Salesman Problem (TSP):" << endl;
    Graph g5(4);
    g5.addEdge(0, 1, 10);
    g5.addEdge(0, 2, 15);
    g5.addEdge(0, 3, 20);
    g5.addEdge(1, 2, 35);
    g5.addEdge(1, 3, 25);
    g5.addEdge(2, 3, 30);

    int tspCost = g5.TSP();
    cout << "Minimum TSP cost: " << tspCost << endl;

    return 0;
}
