#include <iostream>
using namespace std;

int main()
{
    string s = "4193 with words";
    int l;
    for(int i = 0; i < s.length() ; i++)
    {
        l = s[i];
        if(l = 45 || l <= 57 && l >= 48)
        {
            cout << s[i] << " ";
        }
    }
}