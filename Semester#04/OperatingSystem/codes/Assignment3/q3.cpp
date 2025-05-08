#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int shared_var = 0;
int turn = 0; 
int total_threads;

void plus_func(int id) 
{
    while (turn != id); 
    shared_var++;       
    turn = (turn + 1) % total_threads;
}

void minus_func(int id) 
{
    while (turn != id);
    shared_var--;       
    turn = (turn + 1) % total_threads;
}

int main(int argc, char* argv[]) 
{

    if (argc != 3) {
        cout << "Usage: first enter plus then minus" << endl;
        return 1;
    }

    int plus = stoi(argv[1]);
    int minus = stoi(argv[2]);
    total_threads = plus + minus;

    vector<thread> threads;
    int id = 0;

    for (int i = 0; i < plus; ++i)
        threads.push_back(thread(plus_func, id++));

    for (int i = 0; i < minus; ++i)
        threads.push_back(thread(minus_func, id++));

    for (auto& t : threads)
        t.join();

    cout << "Final value of shared variable: " << shared_var << endl;
    return 0;
}

