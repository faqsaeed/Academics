#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num, p=2, a=0, b=0, check=0, k=0;
    cout << "Enter a number ";
    cin >> num;
    bool prime=0;
    if(num==1)
    {
        cout<<"No posible results";
    }
    else
    {
        for (int i=2; i<=num ; i++)
        {   p=2;
            a=0;
            b=0;
            check=0;
            prime=0;
            k=i;
            if (k == 2)
            {
                prime =1;
            }
            else{
                while (p<k) 
              {
                 if (k% p == 0) 
                 {
                     check= 1;
                 }
                 p++;
               }
            }
            if (check==0)
            {
            prime=1;
            }
            if(prime==1)
            {
                a=k;
            } 
            k=num-i;
            p=2;
            check=0;
            prime=0;
            if (k== 2)
            {
                prime =1;
            }
            else{        
                while (p<k) 
              {
                 if (k% p == 0) 
                 {
                     check= 1;
                  }
                  p++;
               }
            }
            if (check==0)
            {
            prime=1;
            }
            if(prime==1)
            {
                b=k;
            } 
            if (a+b==num)
           {
              cout<<a<<" + "<<b<<" = "<<num<<endl;
            }
        }
    }
}