#include <iostream>
using namespace std;

const int rows = 5, col = 30;

void longestPrefix(char arr[rows][col])
{
    for (int i = 0; ; i++)
    {
        if (arr[0][i] == arr[1][i]  && arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i])
        {
            cout << arr[0][i];
        }
        else
        {
            break;
        }
    }
}


int main()
{
    char arr[][col] = { "CharacterLess" , "Chararray" , "Character" , "CharteredAcountant" };
    longestPrefix(arr);

}