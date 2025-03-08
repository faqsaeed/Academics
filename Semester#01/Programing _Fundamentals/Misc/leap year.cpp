#include <iostream>
using namespace std;
int main()
{
    int year ;
    cout<<"Enter the year";
    cin>>year ;
    if(year %4==0 && year %100!=0){
        cout<<"it is a leap year";
    }
    else if(year %100==0 && year %400==0)
    {
        cout<<"It is a leap year";
    }
    else{
        cout<<"It is not a leap year";
    }
}