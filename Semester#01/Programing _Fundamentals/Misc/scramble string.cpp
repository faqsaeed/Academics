#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    string str1 , str2;
    cout << "Enter the first String : ";
    cin >> str1;
    cout << "\nEnter the second String : ";
    cin >> str2;
    int count = 0;
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 != len2)
    {
        cout<< "False";
        return 0;
    }
    else
    {
        for(int i = 0 ;i < len1; i++)
        {
            for(int j = 0 ; j < len2 ; ++j)
            {
                if(str1[i] == str2[j])
                {
                    count++;
                    break;
                }
            }
            if(count - 1 != i)
            {
                cout << "false";
                return 0;
            }
        }
        if ( count == len1)
        {
            cout << "true";
            return 0;
        }

    }

}