#include <iostream>
using namespace std;

int combination(int n, int r) 
{

    if (r == 0 || r == n) 
        return 1;
    

    return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    cout << "C(" << n << ", " << r << ") = " << combination(n, r) << endl;

    cout << "C(5, 3) = " << combination(5, 3) << endl;
    cout << "C(9, 4) = " << combination(9, 4) << endl;

    return 0;
}
