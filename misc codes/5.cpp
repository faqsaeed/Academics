#include <iostream>
#include <string>
using namespace std;

string removeConsecutiveDuplicates(string s) 
{
    if (s.length() <= 1)
        return s;

    if (s[0] == s[1])
        return removeConsecutiveDuplicates(s.substr(1));

    return s[0] + removeConsecutiveDuplicates(s.substr(1));
}

int main() 
{
    string input = "aaaabbbcdddeee";
    string output = removeConsecutiveDuplicates(input);
    cout << "Output: " << output << endl;
    cout << "Enter a string: ";
    cin >> input;
    output = removeConsecutiveDuplicates(input);
    cout << "Output: " << output << endl;

    return 0;
}
