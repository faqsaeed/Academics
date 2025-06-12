#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For reverse function
using namespace std;

// Function to find the shortest path using BFS
bool bfsPath(int start, int end, vector<vector<int>>& adjList, vector<int>& path) {
    int V = adjList.size();
    vector<bool> visited(V, false); // To keep track of visited nodes
    vector<int> parent(V, -1); // To store the parent of each node
    queue<int> q;

    // Start BFS from the source node
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // If the destination node is reached
        if (node == end) {
            // Reconstruct the path from end to start using the parent array
            int current = end;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(), path.end()); // Reverse to get the correct path
            return true;
        }

        // Explore neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    return false; // No path exists
}

// Function to find a path using DFS
bool dfsPath(int node, int end, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& path) {
    visited[node] = true; // Mark the current node as visited
    path.push_back(node); // Add the current node to the path

    if (node == end) return true; // If the destination node is found

    // Explore neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (dfsPath(neighbor, end, adjList, visited, path)) {
                return true; // Path found
            }
        }
    }

    path.pop_back(); // Backtrack if no path is found through this node
    return false;
}

// Function to find all possible paths using DFS
void findAllPaths(int node, int end, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& path) {
    visited[node] = true; // Mark the current node as visited
    path.push_back(node); // Add the current node to the path

    if (node == end) {
        // Print the current path
        for (int p : path) cout << p << " ";
        cout << endl;
    } else {
        // Explore neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                findAllPaths(neighbor, end, adjList, visited, path);
            }
        }
    }

    visited[node] = false; // Backtrack
    path.pop_back(); // Remove the current node from the path
}

// Function to check if the graph is circular (contains a cycle) using DFS
bool isCyclicDFS(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            // If visiting an unvisited neighbor and it leads to a cycle
            if (isCyclicDFS(neighbor, node, adjList, visited)) return true;
        } else if (neighbor != parent) {
            // If a visited neighbor is not the parent, a cycle is found
            return true;
        }
    }
    return false;
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adjList(V); // Adjacency list representation of the graph

    // Example graph
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    // 1. Find the shortest path using BFS
    vector<int> pathBFS;
    int start = 0, end = 5;
    if (bfsPath(start, end, adjList, pathBFS)) {
        cout << "Shortest path using BFS from " << start << " to " << end << ": ";
        for (int node : pathBFS) cout << node << " ";
        cout << endl;
    } else {
        cout << "No path exists between " << start << " and " << end << " using BFS." << endl;
    }

    // 2. Find a path using DFS
    vector<int> pathDFS;
    vector<bool> visitedDFS(V, false);
    if (dfsPath(start, end, adjList, visitedDFS, pathDFS)) {
        cout << "Path using DFS from " << start << " to " << end << ": ";
        for (int node : pathDFS) cout << node << " ";
        cout << endl;
    } else {
        cout << "No path exists between " << start << " and " << end << " using DFS." << endl;
    }

    // 3. Find all possible paths using DFS
    vector<bool> visitedAllPaths(V, false);
    vector<int> pathAllPaths;
    cout << "All possible paths from " << start << " to " << end << ":\n";
    findAllPaths(start, end, adjList, visitedAllPaths, pathAllPaths);

    // 4. Check if the graph is circular (contains a cycle)
    vector<bool> visitedCyclic(V, false);
    bool isCyclic = false;
    for (int i = 0; i < V; ++i) {
        if (!visitedCyclic[i]) {
            if (isCyclicDFS(i, -1, adjList, visitedCyclic)) {
                isCyclic = true;
                break;
            }
        }
    }

    if (isCyclic) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
