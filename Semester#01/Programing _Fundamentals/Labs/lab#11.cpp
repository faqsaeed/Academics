//Lab Manual
//https://docs.google.com/document/d/1HtwUs2E3kEds9nd7szqm31AvUxIBBZHDmIjX8BzMeR8/edit?usp=sharing

#include<iostream>
#include <stdlib.h>

using namespace std;


int fill(char a[][100] , int r , int c)
{

    for (int i = 0 ; i <  r ; i++)
    {
        for (int j=0; j<c; j++ )
        {
            a[i][j] = ' ';
        }
    }
}

void print(char a[][100], int r, int c)
{
    for (int i = 0 ; i < r ; i++ )
    {
        for (int j = 0 ; j < c ; j++ )
        {
            cout<<a[i][j];
            for ( int j = 0; j < 1000000; j++)
            {}
        }
        for ( int j = 0; j < 1000000; j++)
        {}
        cout<<endl;
    }
}

void down(char f[][100], int a , int b, int c , int d)
{
    for ( int i = c+1 ; i < a ; i++ )
    {
        f[i][d] = '|';
    }

}

void up(char f[][100], int a , int b, int c , int d)
{
    
}

void left(char f[][100], int a , int b, int c , int d)
{
    for ( int i = d-1 ; i > 0 ; i--)
    {
        f[c][i] = '-';
    }
}

void right(char f[][100], int a , int b, int c , int d)
{
    for ( int i = d+1 ; i < b ; i++)
    {
        f[c][i] = '-';
    }

}

void all(char f[][100], int a , int b, int c , int d)
{
    right ( f,  a ,  b,  c ,d);
    left ( f,  a ,  b,  c , d);
    up( f,  a , b,  c ,  d);
    down ( f,  a ,  b,  c ,  d);
}

int main()
{
    char ar[100][100];
    int x , y ;
    cout << "Enter max x axis." ;
    cin >> x ;
    cout << "Enter max y axis." ;
    cin >> y;
    
    fill(ar, y, x);
    for (int i = 0 ; i < x ; i++ )
    {
        ar[0][i] = '-' ;
        ar[y][i] = '-' ;
    }
    for ( int j = 0 ; j <= y ; j++ )
    {
        ar[j][0] = '|' ;
        ar[j][x+1] = '|' ;
    }
    int p = x/2;
    int j= y/2;
    ar[p][j]= 'X';
    print(ar , y+2 , x+2);

        int choice;
        cout << "0: shot right \n1: shot left \n2: shot up \n3: shot down \n4: shot all directions" ;
        cin>>choice;
        if(choice==0)
        {
            right(ar, x,y,p,j);
        }
        else if(choice==1)
        {
            left(ar,x,y,p,j);
        }
        else if(choice==2)
        {
            up(ar, x,y,p,j);
        }
        else if(choice==3)
        {
            down(ar, x,y,p,j);
        }
        else if (choice == 4)
        {
            all(ar, x,y,p,j);
        }
        system("CLS"); 
        print(ar , y+2 , x+2);

}
