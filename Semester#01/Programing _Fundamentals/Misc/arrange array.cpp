#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
   srand(time(0));
   int a[1000],s,k=0,m=0,f;
   cout<<"Enter the size";
   cin>>s;
   for(int i=0; i<s; i++ )
   {
      a[i]=rand()%50;
      cout<<a[i]<<endl;
   }
   cout<<endl;
   for(int i=0; i<s; i++)
   {
      m=a[i];
      for(int j=i+1; j<s;j++)
      {
         int l=a[j];
         if(l>m)
         {
            m=l;
            f=j;
         }
      }
      a[f]=a[i];
      a[i]=m;
      cout<<a[i]<<endl;
   }
  
}
