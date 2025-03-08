#include <iostream>
using namespace std;
int main()
{
    int a,sum=0,c=0;
    cout<<"Enter a number";
    cin>>a;
    if (a<0){
        a=-1*a;
    }
    while(a>0){
        c=a%10;
        a=a/10;
        sum=sum+c;
    }
    cout<<sum;

}