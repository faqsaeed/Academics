//lab manual
//https://docs.google.com/document/d/14vZvH4TgGNWesB9A0bdDEEaPD7o1PIEmmZFApiBZy8Q/edit?usp=sharing


#include<iostream>
using namespace std;
void display()
{
   for(int i=1; i<=10; i++)
   {
      cout<<"5 *"<<i<<" = "<<(5*i)<<endl;
   }
}
int seriessum()
{
   int sum=1;
   for(int i=2; i<=1000; i++)
   {
      sum=i+sum;
   }
   return sum;
}
int sumbetween(int a, int b)
{
   int sum=0;
   for(int i=a; i<=b; i++){
      sum=i+sum;
   }
   return sum;
}
void f1()
{
   int ar[1000];
   long long int sum;
   int co=0;
   for(int i=0; i<=995; i++)
   {
      ar[i]=sumbetween(2,i+5);
      sum=ar[i]+sum;
      co++;
   }
   float f=0.00000;
   f=sum/co;
   cout<<f;
}
int main()
{
int a,choice=1,x, y,z;
while(choice>0 && choice<5)
{
   cout<<"Enter a question! ";
   cin>>choice;
   if(choice==1)
   {
      display();
      cout<<endl;
   }
   else if(choice==2)
   {
      a=seriessum();
      cout<<a<<endl;
   }
   else if (choice==3)
   {
      x=2;
      y=1;
      while(x>y&&x>0&&y>0)
      {
         cout<<"strting value";
         cin>>x;
         cout<<"ending value";
         cin>>y;
      }
      int w=sumbetween(x,y);
      cout<<w<<endl;
   }
   else if(choice==4)
   {
      f1();
      cout<<endl;
   }

}
cout<<"bye bye!";
}
