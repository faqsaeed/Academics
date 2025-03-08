#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
   srand(time(0));
   int level=1, comp, human, size,turn=0,a;
   level=(rand()%2);
   size=(rand()%91)+10;
   turn=(rand()%2);
   if(level==0)
   {
      if(turn==0)
      {
         cout<<"Computer will play first!!"<<endl;
         while(1)
         {
            a=(size/2)+1;
            comp=(rand()%a)+1;
            cout<<"Computer has drawn "<<comp<<endl;
            size=size-comp;
            if(size<=0)
            {
               cout<<"human wins";
               break;
            }
            a=(size/2)+1;
            cout<<"Your turn!  ";
            cin>>human;
            while(human>a)
            {
               cout<<"you cant draw more than half of the size"<<endl<<"Draw again!   ";
               cin>>human;
            }
            cout<<"Human has drawn "<<human<<endl;
            size=size-human;
            if(size<=0)
            {
               cout<<"computer wins";
               break;
            }
         }
      }
      else if(turn==1)
      {
         cout<<"Human will play first!!"<<endl;
         while(1)
         {
            a=(size/2)+1;
            cout<<"Your turn!  ";
            cin>>human;
            while(human>a)
            {
               cout<<"you cant draw more than half of the size"<<endl<<"Draw again!   ";
               cin>>human;
            }
            cout<<"Human has drawn "<<human<<endl;
            size=size-human;
            if(size==0)
            {
               cout<<"computer wins";
               break;
            }
            a=(size/2)+1;
            comp=(rand()%a)+1;
            cout<<"Computer has drawn "<<comp<<endl;
            size=size-comp;
            if(size==0)
            {
               cout<<"human wins";
               break;
            }
        }
      }
   }
   else if(level==1)
   {
      if(turn==0)
      {
         cout<<"Computer will play first!!"<<endl;
         while(1)
         {
            a=(size/2)+1;
            if (size==3 || size==7 || size==15 ||size==31 || size==63)
            {
               comp=(rand()%a)+1;
            }
            else
            {
               while (comp>a)
               {
                  int n=(rand()%6)+1;
                  int x=pow(2,n)-1,a;
                  a=size - x;
                  comp = size -a;
               }
            }
            cout<<"Computer has drawn "<<comp<<endl;
            size=size-comp;
            if(size<=0)
            {
               cout<<"human wins";
               break;
            }
            a=(size/2)+1;
            cout<<"Your turn!  ";
            cin>>human;
            while(human>a)
            {
               cout<<"you cant draw more than half of the size"<<endl<<"Draw again!   ";
               cin>>human;
            }
            cout<<"Human has drawn "<<human<<endl;
            size=size-human;
         }
      }
      else if(turn==1)
      {
         cout<<"Human will play first!!"<<endl;
         while(1)
         {
            a=(size/2)+1;
            cout<<"Your turn!  ";
            cin>>human;
            while(human>a)
            {
               cout<<"you cant draw more than half of the size"<<endl<<"Draw again!   ";
               cin>>human;
            }
            cout<<"Human has drawn "<<human<<endl;
            size=size-human;
            if(size==0)
            {
               cout<<"computer wins";
               break;
            }
            a=(size/2)+1;
            if (size==3 || size==7 || size==15 ||size==31 || size==63)
            {
               comp=(rand()%a)+1;
            }
            else
            {
               while (comp>a)
               {
                  int n=(rand()%6)+1;
                  int x=pow(2,n)-1,a;
                  a=size - x;
                  comp = size -a;
               }
            }
            cout<<"Computer has drawn "<<comp<<endl;
            size=size-comp;
            if(size<=0)
            {
               cout<<"human wins";
               break;
            }
         }
      }
   }
}