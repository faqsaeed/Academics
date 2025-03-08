#include<iostream>
using namespace std;

int main()
{
   int n,r,val,check=0,con, x,y,z;
   while (check!=1)
   {
      cout<<"For factorial enter 1"<<endl<<"For permutation enter 2"<<endl<<"For combination(method#1) enter 3"<<endl<<"For combination(method#2) enter 4"<<endl<<"To end programe enter 5       ";
      cin>>con;
      if(con==1)
      {
      cout<<"Enter number.  ";
      cin>>n;
      cout<<n<<"! = ";
      x=n;
      for(int i=1; i<x; i++)
      {
         n=n*i;
      }
      cout<<n<<endl;
      }
      else if(con==2)
      {
      cout<<"Enter two numbers";
      cin>>n>>r;
      cout<<n<<"P"<<r<<" = ";
      r=n-r;
      x=r;
      y=n;
      for(int i=1; i<y; i++)
      {
         n=n*i;
      }
      for(int i=1; i<x; i++)
      {
         r=r*i;
      }
      val=n/r;
      cout<<val<<endl;
      }
      else if(con==3)
      {
      cout<<"Enter two numbers";
      cin>>n>>r;
      cout<<n<<"C"<<r<<" = ";
      int a=n-r;
      x=a;
      y=n;
      z=r;
      for(int i=1; i<y; i++)
      {
         n=n*i;
      }
      for(int i=1; i<z; i++)
      {
         r=r*i;
      }
      for(int i=1; i<x; i++)
      {
         a=a*i;
      }
      val=n/(a*r);
      cout<<val<<endl; 
      }
      else if(con==4)
      {
      cout<<"Enter two numbers";
      cin>>n>>r;
      cout<<n<<"C"<<r<<" = ";
      int a=n-r;
      x=a;
      y=n;
      z=r;
      for(int i=1; i<y; i++)
      {
         n=n*i;
      }
      for(int i=1; i<x; i++)
      {
         a=a*i;
      }
      for(int i=1; i<z; i++)
      {
         r=r*i;
      }
      val=n/a;
      val=val/r;
      cout<<val<<endl;
      }
      else if(con==5)
      {
         check=1;
      }
   }
}