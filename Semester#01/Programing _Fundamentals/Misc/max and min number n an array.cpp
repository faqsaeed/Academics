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
    int size;
    cout << "Enter the size of the array.\n";
    cin >> size;
    fill_array(array, size);
    print_array(array, size);
    int max = array[0];
    int min = array[size - 1];
    
    for(int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i]< min)
        {
            min = array[i];
        }
    }
    cout << "The maximun number in the array is " << max;
    cout << "\nThe minimum number in the array is " << min;
    return 0;

}
