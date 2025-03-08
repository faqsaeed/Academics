#include <iostream>
using namespace std;

int main()
{
    char a[6][6] ={'D','D','D','G','D','D','B','B','D','E','B','S','B','S','K','E','B','K','D','D','D','D','D','E','D','D','D','D','D','E','D','D','D','D','D','G'};
    string str= "GEEKS";
    int check = 0, count = 0;
    int length = str.length();
    for (int  i = 0 ; i < 6 ; ++i)
    {
        for(int j = 0 ; j < 6 ; j++)
        {
            if (a[i][j] == str[0])
            {
                if(a[i+1][j] == str[1])
                {
                    int k = 2;
                    check = 2;
                    while(k < length)
                    {
                        if(a[i + k][j] == str[k])
                        {
                           check++; 
                           k++;
                        }
                        else
                        {
                            break;
                        }

                    }
                    if(check == length)
                    {
                        count++;
                    }
                }

                if(i != 0)
                {
                    if(a[i-1][j] == str[1])
                    {
                        int k = 2;
                        check = 2;
                        while(k < length)
                        {
                            if(a[i - k][j] == str[k])
                            {
                               check++; 
                               k++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(check == length)
                        {
                            count++;
                        }
                    }
                }

                if(a[i][j+1] == str[1])
                {
                    int k = 2;
                    check = 2;
                    while(k < length)
                    {
                        if(a[i][j+k] == str[k])
                        {
                           check++; 
                           k++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(check == length)
                    {
                        count++;
                    }
                }

                if(j != 0)
                {
                    if(a[i][j - 1] == str[1])
                    {
                        int k = 2;
                        check = 2;
                        while(k < length)
                        {
                            if(a[i][j - k] == str[k])
                            {
                               check++; 
                               k++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(check == length)
                        {
                            count++;
                        }
                    }
                }
  
            }
        }
    }
    cout << str << " appears " << count << " time(s) in the given array.";
}