#include <iostream>
using namespace std;

void sort_array(int a[], int size)
{
    int temp;
    for(int i = 0 ; i < ( size - 1 ) ; i++)
    {
        for(int j = 0; j < ( size - i - 1 ) ; j++)
        {
            if (a[j] < a[j + 1])
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
    int arr[10] , size = 0, k;
    cout << "Enter 10 numbers or enter -1 continue. \n";
    for( int i = 0; i < 10 ; i++)
    {
        cin >> arr[i];
        if(arr[i] == -1)
        {
            break;
        }
        else
        {
            size++;
        }
    }

    sort_array(arr , size);

    cout << "Enter a number \t";
    cin >> k;
    cout << k <<"th largest number is " << arr[k - 1];
}