#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

void fill_array(int a[], int size)
{
    srand(time(0));
    for(int i = 0; i < size ; ++i)
    {
        a[i] = rand()%50;
    }
}

void print_array(int a[], int size)
{
    for(int i = 0; i < size ; ++i)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int array[100];
    int size , reverse;
    cout << "Enter the size of the array.\n";
    cin >> size;
    fill_array(array, size);
    print_array(array, size);
    do
    {
        cout << "Enter the number for reversal.\n";
        cin >> reverse;
    }
    while (reverse > size);
    int sub[100];
    for(int i = reverse ,j = 0 ; i < size ; i ++ , j++)
    {
        sub[j] = array[i];
    }
    for(int i = 0, j = size - reverse ; i < reverse ; ++i , ++j)
    {
        sub[j] = array[i];
    }
    
    print_array(sub , size);    
}