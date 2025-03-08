//Lab Manual
//https://docs.google.com/document/d/1XUQoDm-Zbqj3Wv6sC8aXZdDUZ4yvfJVo9p_E4UIR8A4/edit?usp=sharing

#include<iostream>
using namespace std;

void rs(char sentence[]) 
{
    int start =0, end;
    for(int i=0;sentence[i]!='\0';i++)
    {
        int a=sentence[i];
        if(a==32)
        {
            end=i;
        }
        if(end==i)
        {
        while(start<end)
        {
            swap(sentence[start],sentence[end]);
            start++;
            end--;
        }
        }
        start=end;
    }
    cout<<endl;
}

int main()
{
    int choice=1;
    while (choice<3 && choice>0)
    {
        cout<<"Enter question  ";
        cin>>choice;
        if(choice==1)
        {
            char p1[] = "This is the first paragraph with no space at start and no space at end";
            char p2[] = " This is first paragraph with one space at start and no space at end";
            int s1= sizeof(p1)/sizeof(p1[1]);
            int s2= sizeof(p2)/sizeof(p2[1]);
            rs(p1);
            cout<<p1;
            rs(p2);
            cout<<p2;
            
        }
        else if(choice==2)
        {
            char mat1[][100]={"This is the first paragraph with no space at start and no space at end", "This is second line with no space at start and no space at end", "This is third line with no space at start and no space at end" };
            char line1[]="random text for mat2";
            char line2[]="second line of random text for mat2";
            char line3[]="third line of random text for mat2";
           /* char mat2[][100];
            mat2[0] = line1;
            mat2[1] = line2;
            mat2[2] = line3;*/
        }
    }
    
}