#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter three numbers";
    cin>>a>>b>>c;
    if(a>=b && b>c){
        cout<<"a is the greatest";
    }
    if(b>=c && c>a){
        cout<<"b is the greatest";
    }
        if(c>=b && b>a){
        cout<<"c is the greatest";
    }
}