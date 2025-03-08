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
    cout << endl;
}

void sort_array(int a[], int size)
{
    int temp;
    for(int i = 0 ; i < ( size - 1 ) ; i++)
    {
        for(int j = 0; j < ( size - i - 1 ) ; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        } 
    }
}

int main()
{
    int array[100] , arr[100];
    int size , reverse;
    cout << "Enter the size of the array.\n";
    cin >> size;
    fill_array(array, size);
    sort_array( array, size);
    print_array(array, size);
    
    fill_array(arr, size);
    sort_array( arr, size);
    print_array(arr, size);

    int sub [200];
    int i;
    for(i = 0 ; i < size ; i++ )
    {
        sub[i] = array[i];
    }
    for(int k = 0 ; k < size ; ++k, ++i)
    {
        sub[i] = arr[k];
    }

    sort_array( sub, 2*size );
    print_array(sub, 2*size );

    cout << "The median value is ";
    cout << (sub[size] + sub[size - 1]) / 2.00;


}