#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int array(int arr[], int n)
{
    srand(time(0));
    int p;
    cout<<"Enter range ";
    cin>>p;

    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%p;
    }

}

