#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

void fill_array(char a[], int size)
{
    srand(time(0));
    for(int i = 0; i < size ; ++i)
    {
        int l = (rand()%26) + 97;
        a[i] = l;
    }
}

void print_array(char a[] , int size)
{
    for(int i = 0; i < size ; ++i)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}

int main()
{
    char array[100];
    int size;
    cout << "Enter the size of the array.\n";
    cin >> size;
    fill_array( array, size );
    print_array( array , size );
    int count = 0;
    int harm = 1;
    for ( int i = 0 ; i < size ; ++i)
    {
        while(array[i] + 1 == array[i+1])
        {
            harm++;
            i++;
        }
        if( harm > count)
        {
            count = harm;
        }
        harm = 0;
    }
    cout << "The number of consecutive elements is : \t" << count << endl;
}