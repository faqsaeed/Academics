#include <iostream>
using namespace std;

class Graphs {
private:
    int** Matrix;      // Adjacency matrix
    int vertices;      // Number of vertices
    bool isDirected;   // 0 = undirected, 1 = directed

public:
    Graphs(int Tvertices, bool dir) 
    {
        vertices = Tvertices;
        isDirected = dir;
        Matrix = new int*[vertices];

        for (int i = 0; i < vertices; i++) 
        {
            Matrix[i] = new int[vertices]();
        }
    }

    bool addEdge(int x, int y) 
    {
        if (x >= vertices || y >= vertices) 
            return false;

        Matrix[x][y] = 1;

        if (!isDirected) Matrix[y][x] = 1;
            return true;
    }

    bool isConnected(int x, int y) 
    {
        if (x >= vertices || y >= vertices)     
            return false;

        return Matrix[x][y] == 1;
    }

    void printGraph() 
    {
        for (int i = 0; i < vertices; i++) 
        {
            for (int j = 0; j < vertices; j++) 
            {
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graphs() 
    {
        for (int i = 0; i < vertices; i++) 
        {
            delete[] Matrix[i];
        }
        delete[] Matrix;
    }
};

int main() {
    Graphs graph(4, true);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << "Adjacency Matrix Representation:" << endl;
    graph.printGraph();

    cout << "\nIs there a connection from 0 to 1? " << (graph.isConnected(0, 1) ? "Yes" : "No") << endl;
    cout << "Is there a connection from 3 to 2? " << (graph.isConnected(3, 2) ? "Yes" : "No") << endl;

    return 0;
}
