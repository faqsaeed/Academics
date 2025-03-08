#include <iostream>
using namespace std;
int main()
{
   int n, count=1, big=0, m;
   cout<<"Enter the number ";
   cin>>n;
   n=10;
   for(int i=1; i<=n; i++)
   {
      int k=i;
      count=1;
   while(k>1)
   {
      if(k%2==0)
      {
        k=k/2;
        count++;
      }
      else
      {
        k=3*k+1;
        count++;
      }
   }
      if(count>big)
      {
        big=count;
        m=i;
      }
   }

   cout<<m;
}
