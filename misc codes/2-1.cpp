#include <iostream>
#include <queue>
#include <unistd.h> // for sleep function
using namespace std;

void display(queue<int> people) 
{
    while (!people.empty()) 
    {
        cout << people.front() << " ";
        people.pop();
    }
    cout << endl;
}


void josephus(int n, int k) 
{
    queue<int> people;
    
    for (int i = 1; i <= n; i++) 
    {
        people.push(i);
    }

    int count = 0;
    
    while (people.size() > 1) 
    {
        for (int i = 0; i < k - 1; i++) 
        {
            int temp = people.front();
            people.pop();
            people.push(temp);
        }

        int executedPerson = people.front();
        people.pop();
        
        
        system("clear");
        cout << endl << "Person " << executedPerson << " is executed." << endl;

        // Display remaining people
        display(people);
        
        // Wait for 1.5 seconds
        sleep(1.5);
    }
    system("clear");
    cout << "Person " << people.front() << " is left." << endl;
}


int main()
{
    int n, k;

    do
    {
        cout << "Enter the number of people (N): ";
        cin >> n;
    }
    while(n <= 0);



    do
    {
        cout << "Enter the step count (K): ";
        cin >> k;
    } 
    while (k <= 0 || k > n);
    
    

    josephus(n, k);

    return 0;
}

