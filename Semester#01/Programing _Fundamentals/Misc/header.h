#include <iostream>

using namespace std;

int fill(char a[][70], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = ' ';   
        }
    }
}

void make_grid(char a[][70], int x_axis, int y_axis)
{
    for (int i = 0; i < x_axis; i++)
    {
        a[0][i] = '-';
        a[y_axis][i] = '-';
    }
    for (int j = 0; j <= y_axis; j++)
    {
        a[j][0] = '|';
        a[j][1] = '|';
    }
}

void print(char a[][70], int x_axis, int y_axis)
{
    for (int i=0;i<x_axis; i++)
    {
        for (int j=0; j<y_axis; j++ )
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}