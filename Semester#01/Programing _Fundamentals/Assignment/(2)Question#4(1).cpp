#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int x1, x2,x3,y1,y2,y3,m1=0.000,m2=0.000,m3=0.000;
    cout<< "Enter x1 cordinate";
    cin>> x1;
    cout<< "Enter x2 cordinate";
    cin>> x2;
    cout<< "Enter x3 cordinate";
    cin>> x3;
    cout<< "Enter y1 cordinate";
    cin>> y1;
    cout<< "Enter y2 cordinate";
    cin>> y2;
    cout<< "Enter y3 cordinate";
    cin>> y3;
    m1 = (y2-y1)/(x2-x1);
    m2  = (y3 - y2)/ (x3-x2) ;
    m3 = (y3-y1)/(x3 - x1);
    switch(m1==m2==m3) {
        case 1 :
        cout << "Coinear";
        break;

        case 0 :
        cout<< "Non coinear";
        break;

    }
}