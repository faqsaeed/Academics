#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int generateRandomNumber(){
    srand(time(0));
    return (1+ rand()%20);
}

int main()
{
    int number =generateRandomNumber();
    int guess = 0;
    
    while(guess != number )
    {
        cout << "Enter your guess"; 
        cin>>guess ; 
        if(guess > number ){
            cout<<"Entered number is higher"<<endl;
        }
        else if(guess < number )
        {
            cout<<"Entered number is lower"<<endl;
        }
      
    }
 cout<<"YOU WIN";
}