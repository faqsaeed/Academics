#include <iostream>
using namespace std;

int main()
{
    string s = "   fly me   to   the moon  ";
    for(int i = s.length() ; i > 0 ; i--)
    {
        while( s[i] == ' ')
        {
            i--;
        }

        int count = 0;

        while( s[i] != ' ' )
        {
            count++;
            i--;
        }
        cout << "Length of the last word is " << count;
        return 0;
    }
}