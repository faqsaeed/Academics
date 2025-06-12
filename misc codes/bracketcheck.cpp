#include <iostream>
#include <stack>
#include <string>

using namespace std;


    bool isValid(string s) 
    {
        stack<char> bracket;
        int size = s.length();
        for(int i = 0; i < size; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                bracket.push(s[i]);
                cout << int(s[i]);
                continue;
            }
            cout<< int(bracket.top());
            if(!(s[i] != (bracket.top() + 1) || s[i] != (bracket.top() + 2)) )
            {
                return false;
            }
            bracket.pop();
        }
        return true;
        
    }


int main()
{
    string s = "(]";
    cout << (isValid(s) ? "yes": "no");
}
