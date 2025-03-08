#include <iostream>
using namespace std;
int main()
{
    int limit, i = 1 , a = 0 , b = 1 , c;
    cout << "Enter the limit";
    cin >> limit;
    cout << a << " " << b;
    while(i < limit){
    c = a + b;
    cout << " " << c;
    a = b;
    b = c;
    i++;
    }

}