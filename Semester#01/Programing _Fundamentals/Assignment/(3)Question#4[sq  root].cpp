#include<iostream>
using namespace std;
int main()
{
   float a=1.0000, n=1.0000000;
   while(n!=-1)
   {
      cout<<"Enter a number(to terminate enter negative vaue) ";
      cin>>n;
      if(n!=-1)
      {

         for(int i=1; i<=10;i++)
         {
            a=(a+n/a)/2;
         }
         cout<<a<<endl;
      } 
   }
}