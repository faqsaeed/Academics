#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib> 
#include <ctime>   
using namespace std;

// Function to print the grid
void printGrid(const vector<string>& grid) 
{
    for (const auto& row : grid) 
    {
        cout << row << endl;
    }
    cout << "------------------" << endl;
}

bool isValid(int x, int y, int n, int m, const vector<string>& grid, vector<vector<bool>>& visited) 
{
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '.' && !visited[x][y];
}

bool dfs(int x, int y, int n, int m, vector<string>& grid, vector<vector<bool>>& visited) 
{
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;
    grid[x][y] = 'o';


    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!s.empty()) 
    {
        auto [cx, cy] = s.top();
        s.pop();
        printGrid(grid);

        if (cx == n - 1 && cy == m - 1) return true;

        for (int i = 0; i < 4; i++) 
        {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (isValid(nx, ny, n, m, grid, visited)) 
            {
                s.push({nx, ny});
                visited[nx][ny] = true;
                grid[nx][ny] = 'o';
            }
        }
    }
    return false;
}

bool bfs(int x, int y, int n, int m, vector<string>& grid, vector<vector<bool>>& visited) 
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    grid[x][y] = 'o';

    // Directions for movement: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) 
    {
        auto [cx, cy] = q.front();
        q.pop();
        printGrid(grid);

        if (cx == n - 1 && cy == m - 1) 
            return true; 

        for (int i = 0; i < 4; i++) 
        {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (isValid(nx, ny, n, m, grid, visited)) 
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                grid[nx][ny] = 'o';
            }
        }
    }
    return false;
}


vector<string> generateRandomGrid(int n, int m) 
{
    vector<string> grid(n, string(m, '.')); // Initialize grid with open cells (.)
    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (rand() % 4 == 0) 
                grid[i][j] = 'x';
        }
    }

    grid[0][0] = '.'; // starting cell 
    grid[n - 1][m - 1] = '.'; // destination cell
    return grid;
}

int main() 
{
    int n, m, choice;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<string> grid;
    cout << "Choose grid input method:\n";
    cout << "1. Manual Input\n";
    cout << "2. Random Grid Generation\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the grid (use '.' for open cells and 'x' for blocked cells):" << endl;
        grid.resize(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> grid[i];
        }
    } 
    else if (choice == 2) 
    {
        grid = generateRandomGrid(n, m);
        cout << "Generated Random Grid:" << endl;
        printGrid(grid);
    } 
    else 
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    vector<string> dfsGrid = grid;
    vector<vector<bool>> visitedDFS(n, vector<bool>(m, false));
    cout << "DFS Traversal:" << endl;

    if (dfs(0, 0, n, m, dfsGrid, visitedDFS))
        cout << "DFS Result: Path found!" << endl;
     else 
        cout << "DFS Result: Path not found." << endl;
    

    vector<string> bfsGrid = grid;
    vector<vector<bool>> visitedBFS(n, vector<bool>(m, false));
    cout << "BFS Traversal:" << endl;

    if (bfs(0, 0, n, m, bfsGrid, visitedBFS))
        cout << "BFS Result: Path found!" << endl;
    else 
        cout << "BFS Result: Path not found." << endl;
    
    return 0;
}
