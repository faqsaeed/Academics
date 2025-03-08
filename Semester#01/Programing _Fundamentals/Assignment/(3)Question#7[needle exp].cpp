#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int main()
{
   float yh=0.0000,yl=0.0000, count=0, t=0.00000, an=0.000000;
   srand(time(0));
   for(int i=1; i<=500; i++)
   {
      yl=(rand()%3);
      an=(rand()%181);
      an=sin(an);
      yh=yl+an;
      if (yh>=0 && yh<=2)
      {
         count++;
      }
   }
   t=count/500;
   cout<<t;

}