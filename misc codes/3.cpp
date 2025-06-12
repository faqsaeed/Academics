#include <iostream>
#include <string>
using namespace std;

void print01(int k, string current = "") 
{
    if (current.length() == k) 
    {
        cout << current << endl;
        return;
    }
    print01(k, current + "0");
    print01(k, current + "1");
    
}

int main() 
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    print01(k);
}
