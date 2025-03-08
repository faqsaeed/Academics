//Lab Manual
//https://docs.google.com/document/d/1NgppRPcR8JhyWY4LoC-h5Iy08rDv0s77/edit?usp=sharing&ouid=110368916846949992347&rtpof=true&sd=true

#include <iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
   int choice=1, a1,b,c,num,room=0,total=0,n,l,sum,f[5],e[5],k;
   float a=0.00000;
   while(choice>0 && choice<=10)
   {
      cout<<"Enter Question number(1-10)  ";
      cin>>choice;
      if(choice==1)
      {
         for(int i=1; i<=25; i++)
         {
            if(i%2!=0)
            {
               a=sqrt(i);
               cout<<a<<endl;
            }
         }

      }
      else if(choice==2)
      {
         num=2;
         a1=1;
         while(num>1)
         {
            cout<<"Enter the number";
            cin>>num;
            if(num>1)
            {
               int b=num;
               for(int i=1; i<num;i++)
               {
                  b=b*i;
               }
               cout<<b<<endl;
            }
         }
      }
      else if(choice==3)
      {
         cout<<"Enter exponent";
         cin>>a1;
         cout<<"enter base";
         cin>>b;
         do
         {
           b=b*b;
           a1--;
         }
         while(a1>1);
         

      }
      else if(choice==4)
      {
         cout<<"Enter the number     ";
         cin>>a1;
         cout<<"Enter the length  ";
         cin>>b;
         for(int i=1; i<=b;i++)
         {
            cout<<a1<<"*"<<i<<"="<<(a1*i)<<endl;
         }
      }
      else if(choice==5)
      {
         cout<<"Enter the number of floors     ";
         cin>>a;
         for(int i=1; i<=a;i++)
         {
            if(i!=13)
            {
               cout<<"current floor is"<<i;
               cout<<"Total rooms? ";
               cin>>b;
               cout<<"Ocupied room? ";
               cin>>c;
               total=total+b;
               room=room+c;
            }
         }
         cout<<"total rooms are "<<total<<endl;
         cout<<"occupied rooms are "<<room<<endl;
         float p=0.00;
         p=room/total*100;
         cout<<"percentage is "<<p;
      }
      else if(choice==6)
      {
         cout<<"Enter the starting number  ";
         cin>>a1;
         cout<<"enter the ending point";
         cin>>b;
         do
         {
            for(int i=1; i<=a1; i++)
            {
            cout<<a;
            }
            cout<<endl;
            a1--;
         }
         while(a1>=b);
      }
      else if(choice==7)
      {
         sum=0;
         cout<<"Enter thr limit";
         cin>>n;
         l=n;
         for(int i=1; i<=n; i++)
         {
            cout<<i<<"^2+";
            l=pow(i,2);
            sum=sum+l;
         }
         cout<<sum;
      }
      else if(choice==8)
      {
         cout<<"enter the width ";
         cin>>a1;
         cout<<"Enter the height";
         cin>>b;
         for(int i=1; i<=a1; i++)
         {
            cout<<"=";
         }
         cout<<endl;
         for(int i=1; i<b; i++)
         {
            cout<<"=";
            for(int j=2; j<b; j++)
            {
               cout<<" ";
            }
            cout<<"="<<endl;
         }
         for(int i=1; i<=a1; i++)
         {
            cout<<"=";
         }
      }
      else if(choice==9)
      {
         srand(time(0));
         sum=0;
         for(int i=0; i<5; i++)
         {
            f[i]=rand()%50;
            cout<<f[i]<<endl;
            sum=sum+f[i];
         }
         cout <<sum;
      }
      else if(choice==10)
      {
         sum=0;
         for(int i=0; i<5; i++)
         {
            cout<<"Enter values ";
            cin>>f[i];
         }
         k=0;
         for(int i=0; i<5; i++)
         {
            e[k]=f[i];
            k++;
         }
         for(int i=0; i<5; i++)
         {
            f[i]=e[k];
            k--;
         }
         for(int i=0;i<5; i++)
         {
            cout<<f[i]<<endl;
         }
      }
   }
}







   
