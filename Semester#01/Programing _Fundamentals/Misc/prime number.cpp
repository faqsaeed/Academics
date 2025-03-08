#include <iostream>
#include <cmath>

using namespace std;

int P(int num)
 {
    
    bool a;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num <= 1)
    {
        a=0;
    }
     else if (num == 2) {
        a=1;
    } 
    else
     {
        int i = 2;

        while (i <= sqrt(num)) 
        {
            if (num % i == 0) 
            {
                a=0;
                return 0;
            }
            i++;
        }

        a=1;
    }

    return 0;
}
int main()
{
    int x;
    cin>>x;
    bool p=P(x);
    cout<<p;
    
}