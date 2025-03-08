#include <iostream>
using namespace std;
int main ()
{
    int a,b,c,d;
    cout << "Enter two numbers ";
    cin >> a >> b;
    c = 1;
    while (a>c || b>c)
    {
        if (a%c==0 && b%c==0)
        {
            d=c;
        }
        c++;
    }
    cout << "GSD is " << d;
}