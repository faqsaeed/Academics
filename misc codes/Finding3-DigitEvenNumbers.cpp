#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) 
{
    int size = digits.size();
    vector<int> result;
    for(int i = 0 ; i < size; i++)
    {
        if(digits[i] == 0)
            continue;
        
        for(int j = 0; j < size; j++)
        {
            if(i == j)
                continue;
            for(int k = 0; k < size; k++)
            {
                if(i == k || j == k || digits[k] % 2 == 1)
                    continue;

                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                result.push_back(number);
            }
        }
    }
         
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;

}

int main()
{
    vector<int> digits = {2, 1, 3, 0};
    vector<int> evenNumbers = findEvenNumbers(digits);
    
    cout << "Even numbers: ";
    for(int num : evenNumbers)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << endl;

    digits = {2, 2, 8, 8, 2};
    evenNumbers = findEvenNumbers(digits);
    
    cout << "Even numbers: ";
    for(int num : evenNumbers)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << endl;

    digits = {3, 7, 5};
    evenNumbers = findEvenNumbers(digits);
    for(int num : evenNumbers)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << endl;

    return 0;               
}