#include <iostream>
using namespace std;
int main()
{
    int number = 0 , digits = 0 , sum = 0 , average = 0 ;
    while (number>=0)
    {
        cout << "Enter a number ";
        cin >> number;
        if (number>=0)
        { 
            sum = number + sum;
            digits++;
        }
    }
    average = sum/digits;
    cout << "average is " << average;
}
