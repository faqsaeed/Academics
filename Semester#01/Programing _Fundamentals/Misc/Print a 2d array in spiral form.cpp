#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

void fill_array(int a[][100], int size)
{
    srand(time(0));
    for(int i = 0; i < size ; ++i)
    {
        for (int j = 0 ; j < size ; ++j)
        {
            a[i][j] = rand()%50;
        }
    }
}

void print_array(int a[][100], int size)
{
    for(int i = 0; i < size ; ++i)
    {
        for(int j =0 ; j < size ; j++)
        {
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int array[100][100];
    int size ;
    cout << "Enter the size of the array.\n";
    do
    {
        cin >> size;
    }
    while(size < 0 && size > 100);
    fill_array(array, size);
    print_array(array, size);

    for ( int i = 0 ; i < size ; ++i)
    {
        if (i % 2 == 0)
        {
            for( int j = 0 ; j < size ; j++)
            {
                cout<< array[j][i] << "  ";
            }
        }
        else
        {
            for( int j = size - 1 ; j >= 0 ; j--)
            {
                cout<< array[j][i] << "  ";
            }
        }
    }
}