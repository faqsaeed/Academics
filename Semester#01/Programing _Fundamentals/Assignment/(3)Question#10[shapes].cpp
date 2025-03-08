#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int rows;
   cout<<"part A"<<endl;
   cout<<"Enter the number of rows!!  ";
   cin>>rows;
   for(int i=0; i<rows; i++)
   {
      for(int j=0; j<rows; j++)
      {
         if(j+i>=rows)
         {
            cout<<" ";
         }
         else
         {
            cout<<"*";
         }
      }
      for(int j=0; j<rows; j++)
      {
         if(j<i)
         {
            cout<<" ";
         }
         else
         {
            cout<<"*";
         }
      }
      cout<<endl;
   }
   for(int i=1; i<=rows; i++)
   {
      for(int j=1; j<=rows; j++)
      {
         if(j<=i )
         {
            cout<<"*";
         }
         else
         {
            cout<<" ";
         }
      }
      for(int j=1; j<=rows; j++)
      {
         if(j+i>rows )
         {
            cout<<"*";
         }
         else
         {
            cout<<" ";
         }
      }
      cout<<endl;
   }
   cout<<"part B"<<endl;
   cout<<"Enter the number of rows!!  ";
   cin>>rows;
   for(int i=1; i<=rows; i++)
   {
      for(int j=1; j<=rows; j++)
      {
         if(j<=i )
         {
            cout<<"*";
         }
         else
         {
            cout<<" ";
         }
      }
      for(int j=1; j<=rows; j++)
      {
         if(j+i>rows )
         {
            cout<<"*";
         }
         else
         {
            cout<<" ";
         }
      
      }
      cout<<endl;
   }
   for(int i=0; i<rows; i++)
   {
      for(int j=0; j<rows; j++)
      {
         if(j+i>=rows)
         {
            cout<<" ";
         }
         else
         {
            cout<<"*";
         }
      }
      for(int j=0; j<rows; j++)
      {
         if(j<i)
         {
            cout<<" ";
         }
         else
         {
            cout<<"*";
         }
      }
      cout<<endl;
   }
   cout<<"part C"<<endl;
   cout<<"Enter the number of rows!!  ";
   cin>>rows;
   char dig;
   cout<<"Enter the charactee you want to print!  ";
   cin>>dig;
   for(int i=0; i<rows; i++)
   {
      int k=i+1;
      for(int j=0; j<rows; j++)
      if(j==i || j==rows-k)
      {
         cout<<" ";
      }
      else
      {
         cout<<dig;
      }
      cout<<endl;
   }
   cout<<"part D"<<endl;
   cout<<"Enter the number of rows!!  ";
   cin>>rows;
   for(int i=1; i<=rows; i++)
   {
      for(int j=1; j<=(2*rows); j++)
      {
         if(i==j || j==2*rows-i )
         {
            cout<<i;
         }
         else
         {
            cout<<" ";
         }
      }
      cout<<endl;
   }
   for(int i=rows-1; i>=1; i--)
   {
      for(int j=(2*rows); j>=1; j--)
      {
         if(i==j || j==2*rows-i+1)
         {
            cout<<i;
         }
         else
         {
            cout<<" ";
         }
      }
      cout<<endl;
   }
   cout<<"part D"<<endl;
   cout<<"Enter the max digit ";
   cin>>rows;
   cout<<"*";
   for (int i = 1; i <= rows; i++) 
   {
      cout<<"*";
      for (int j = 1; j <= i; j++)
      {
         cout << j;
      }
      if (i > 1) 
      {
        for (int j = i - 1; j >= 1; j--) 
        {
            cout << j;
        }
      }
      cout << "*" << endl;
   }
   for (int i=rows-1; i>=1; i--)
   {
      cout<<"*";
      for(int j=1; j<=i; j++)
      {
        cout<<j;
      }
      for(int j=i-1; j>=1; j--)
      {
        cout<<j;
      }
      cout<<"*"<<endl;
   }
}