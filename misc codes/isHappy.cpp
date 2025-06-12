#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Sudoku{
private:
    vector<vector<int>> solved;
    vector<vector<bool>> display;

    bool checkPossible(const int& x, const int y, const int& val)
    {
        for(int i = 0; i < 9; i++)
        {
            if(solved[x][i] == val || solved[i][y] == val)
                return false;    
        }
        return true;
    }
public:

    void insert(const int& x, const int y, const int& val)
    {
        if(checkPossible(x,y,val) && !display[x][y])
        {
            solved[x][y] = val;
            display[x][y] = true;
        }
    }
    
    
};

