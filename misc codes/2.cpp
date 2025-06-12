#include <iostream>
#include <string>
using namespace std;

string putCommas(string str) 
{
    int len = str.length();

    if (len <= 3) 
        return str;
    
    return putCommas((str.substr(0, len - 3))) + "," + str.substr(len - 3);
}

int main() 
{
    string number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Formatted number: " << putCommas(number) << endl;

}
