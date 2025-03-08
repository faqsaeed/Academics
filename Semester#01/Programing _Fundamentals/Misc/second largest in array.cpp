#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
   srand(time(0));
   int a[1000],s,k=0,m=0;
   cout<<"Enter the size";
   cin>>s;
   for(int i=0; i<s; i++ )
   {
      a[i]=rand()%50;
      cout<<a[i]<<endl;
      if(a[i]>k)
      {
         k=a[i];
      }
   }
   m=a[0];
   for(int i=0; i<s; i++ )
   {
      if(a[i]<k &&a[i]>m )
      {
         m=a[i];
      }
   }
   cout<<"================="<<m;
   
}