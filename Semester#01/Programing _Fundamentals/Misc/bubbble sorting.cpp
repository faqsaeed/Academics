#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fill(int b[], int n)
{
    srand(time(0));
    for(int i=0;i<n; i++)
    {
        b[i]=rand()%20;
    }
}

void bubble(int b[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (b[j] > b[j + 1]) 
            {
                swap(b[j], b[j + 1]); 
            }
        }
    }
}

void print(int b[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<b[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int a[10];
    int s=sizeof(a)/sizeof(a[1]);
    fill(a,s);
    print(a,s);
    bubble(a,s);
    print(a,s);
}