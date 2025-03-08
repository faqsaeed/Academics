#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int number, digits =0, sum=0;
    cout << "Enter a number\n";
    cin >> number;
    int temp = number;
    while(temp)
    {
        digits++;
        temp /= 10;
    }
    for(int i = 0; i < digits ; ++i)
    {
        int current , left = number;
        current = left % 10;
        left /= 10;
        sum = pow(current , digits) + sum;
    }
    if(sum = number)
    {
        cout << "it is an Armstrong number";
    }
    else
    {
        cout << "it is not an Armstrong number";
    }
}