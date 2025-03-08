#include <iostream>
#include <cmath>

using namespace std;


int P(int num)
{
    
    bool a;
    if (num <= 1)
    {
        a=0;
    }
     else if (num == 2) {
        a=1;
    } 
    else
    {
        for(int i = 2; i <= sqrt(num);i++)

        if (num % i == 0) 
        {
            a=0;
            return 0;
        }
        a=1;
    }
    return a;
}