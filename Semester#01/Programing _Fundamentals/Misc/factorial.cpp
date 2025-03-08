#include <iostream>
using namespace std;
int main(){
    unsigned long long int n,p;
    cin>>n;
    p=n;
    if (n<0){
        cout<<"Enter a vaid number";
    }
    else
    {
        for(int i=1; i<p; i++)
        {
            n=n*i;
        }
        cout<<n;
    }   
}