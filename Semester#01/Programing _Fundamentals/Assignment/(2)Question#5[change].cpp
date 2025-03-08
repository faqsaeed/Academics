#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f,g;
    cout<<"Enter the amount due(in pennies)";
    cin>> a;
    cout<< "Enter the customer's receipt(in pennies) ";
    cin>>b;
    c=a-b;
    d=c/100;
    c=c%100;
    e=c/25;
    c=c%25;
    f=c/10;
    c=c%10;
    g=c/5;
    c=c%5;
    cout<< "Change due is: "<<d<< " dollars "<< e<< " quarters "<< f << " dimes "<< g << " nickes "<< c << " cents";
}