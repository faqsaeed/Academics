#include<iostream>
using namespace std;

int mis(int a[], int n)
{
    int sum2=0;
    int sum1=0;
    for(int i=1; i<=n; i++)
    {
        sum1=sum1+i;
    }
    for(int i=0; i<n-1; i++)
    {
        sum2=sum2+a[i];
    }
    n=sum1-sum2;
    return n;
}
int main()
{
    int a[] = {6,1,2,8,3,4,7,10,5};
    int y=mis(a,10);
    cout<<y;
}