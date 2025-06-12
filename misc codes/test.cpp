#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main()
{
cout<<"A\n";
pid_t p1 = fork();
if( p1 == 0 )
{

cout<<"B\n";
fork();

}
else
{

cout<<"C\n";

}
cout<<"D\n";
return 0;
}
