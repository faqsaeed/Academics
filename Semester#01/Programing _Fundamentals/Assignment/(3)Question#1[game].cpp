#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int main()
{
    int user1=0, user2=0;
    cout << "Cick anywhere to continue "<<endl;
    for ( ; ;)
    {
        if ( user1<20 && user2<20)
        {
            getch();
            srand(time(0));
            int a = 1 + (rand()%6);
            if (user1 +a<=20)
            {
                user1 = user1 + a;
                cout<<"user 1 has rolled " << a << endl << "Total score of User 1 is " << user1<<endl;
            }
            else
            {
                cout << "User 1 has rolled " << a << " which goes beyond 20 hence no move"<<endl;
            }
            if (user1==20)
            {
                cout << "User1 has won the game ";
                break;
            }
            getch();
            srand(time(0));
            a = 1 + (rand()%6);
            if (user2 +a<=20)
            {
                user2 = user2 + a;
                cout<<"user 2 has rolled " << a << endl << "Total score of User 2 is " << user2<<endl;
            }
            else
            {
                cout << "User 2 has rolled " << a << " which goes beyond 20 hence no move"<<endl;
            }
            if (user2==20)
            {
                cout << "User 2 has won the game ";
                break;
            }
        }
    }
} 