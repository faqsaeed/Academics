#include<iostream>
using namespace std;
int main()
{
   int up;
   cout<< "enter the length of the kite!!";
   cin>>up;
   
   for(int i=0; i<=up; i++)
   {
      for(int j=i;j <up; j++ )
      {
         cout<<" ";
      }
      cout<<"*";
      for(int j=1; j<=i;j++ )
      {
         cout<<" ";
      }
      cout<<"|";
      for(int j=i; j>0; j--)
      {
         cout<<" ";
      }
      cout<<"*";
      cout<<endl;
   }
   cout<<"*";
   for(int j=1; j<=2*up+1; j++)
   {
      cout<<"-";
   }
   cout<<"*"<<endl;
   for(int i=0; i<2*up; i++)
   {
      for(int j=0; j<i/2; j++)
      {
         cout<<" ";
      }
      cout<<"*";
   
      for(int j=i/2;j<=up-1;j++)
      {
         cout<<" ";
      }
      cout<<"|";
      for(int j=up; j<=2*up-i/2; j++ )
      {
         cout<<" ";
      }
      cout<<"*";
      cout<<endl;
   }
}
      
