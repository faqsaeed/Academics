#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"enter number of rows.";
    cin>>a;
    for(int i=1; i<a; i++)
    {
        for(int j=1 ;i>=j;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}