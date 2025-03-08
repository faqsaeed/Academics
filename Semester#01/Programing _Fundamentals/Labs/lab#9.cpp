//lab manual
//https://docs.google.com/document/d/13aXkXW93qoI6IWyN6-oUkKvebBBTOCTqdpAd-XNpLDU/edit?usp=sharing


#include <iostream>
using namespace std;

int countWords(char par[], int size){
    int a=0;
        for (int i = 0; i <size; i++) 
    {
        if(par[i] != ' ' || par[i] != '\n')
        {
            a++; 
        }
    }
    return a;
}

void am(char a[], char b[], int s1, int s2)
{
    for (int i = 0; i <s1; i++) 
    {
       cout<< a[i];
    }
    cout<<" ";
    for (int i = 0; i <s2; i++) 
    {
       cout<< b[i];
    }  
}

int main(int argc, char *argv[])
{
    int choice;
    cin>> choice;
    if(choice==1)
    {
   //char array4[2] = {'1','2'};
   //cout << array4; // can you predict the output?
   
    char p1[] = "This is first paragraph with no space at start and no space at end";
    char p2[] = " This is first paragraph with one space at start and no space at end";
    char p3[] = " This is first paragraph with one space at start and one space at end ";
    char p4[] = "    this is a  sparse     paragraph     ";
    char p5[] = "    it is   multiline paragraph \n second line of paragraph ";
    
    int words1 = countWords(p2,sizeof(p2));
    cout << words1;

    int x;
    cin >> x;
    return 0;
}
if (choice==2)
{
    char p1[] = "This is first paragraph with no space at start and no space at end";
    int sa=sizeof(p1);
    char p2[] = " This is first paragraph with one space at start and no space at end";
    int se= sizeof(p2);
    am(p1, p2, sa, se);
}
}