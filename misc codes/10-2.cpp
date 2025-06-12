#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graphs {
private:
    vector<vector<int>> adjList; // Adjacency list
    int vertices;               // Number of vertices
    bool isDirected;            // 0 = undirected, 1 = directed

public:
    Graphs(int Tvertices, bool dir) 
    {
        vertices = Tvertices;
        isDirected = dir;
        adjList.resize(vertices);
    }

    bool addEdge(int x, int y) 
    {
        if (x >= vertices || y >= vertices) 
            return false;
        
        adjList[x].push_back(y);
        if (!isDirected) 
            adjList[y].push_back(x);
        
        return true;
    }

    bool isConnected(int x, int y) 
    {
        if (x >= vertices || y >= vertices) 
            return false;

        return find(adjList[x].begin(), adjList[x].end(), y) != adjList[x].end();
    }

    void printGraph() 
    {
        for (int i = 0; i < vertices; i++) 
        {
            cout << i << ": ";
            for (int j : adjList[i]) 
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    Graphs graph(5, false);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Adjacency List Representation:" << endl;
    graph.printGraph();

    cout << "\nIs there a connection between 0 and 4? " << (graph.isConnected(0, 4) ? "Yes" : "No") << endl;
    cout << "Is there a connection between 2 and 4? " << (graph.isConnected(2, 4) ? "Yes" : "No") << endl;

    return 0;
}
