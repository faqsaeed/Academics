#include<iostream>
using namespace std;

int main()
{
   int num=1, a,b,c,sum1=0,sum2=0,sum;
   while(num<9999999)
   {
      cout<<"Enter your 8-digit credit card number. ";
      cin>>num;
   }
   a=num;
   for(int i=1 ; i<=4 ; i++)
   {
      b=a%10;
      sum1=sum1+b;
      a=a/100;
   }
   a=num/10;
   for(int i=1 ; i<=4 ; i++)
   {
      b=a%10;
      b=2*b;
      sum2=(b/10)+(b%10)+sum2;
      a=a/100;
   }
   sum=sum1 + sum2;
   if(sum%10==0)
   {
      cout<<"It is a valid number";
   }
   else
   {
      a=sum/10;
      cout<<"there's a difference of "<<a<<"digits in the check of your credit card";
   }
}