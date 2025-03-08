#include <iostream>
using namespace std;
int main()
{
    int rooms, days, price;
    float tax=0.00000, disc=0.0000, ppr=0.0000, total=0.00000, totalt=0.000000 ;
    cout<< "Number of rooms ";
    cin>> rooms;
    cout<< "Number of days ";
    cin>> days;
    cout<< "Base price per room ";
    cin>> price;
    cout<< "Percentage of tax ";
    cin>> tax;
    if(rooms>=10)
    {
        disc = disc+10;
    }
    else if(rooms>=20)
    {
        disc= disc=20;
    }
    else if(rooms>=30)
    {
        disc=disc+30;
    }
    if(days>=3)
    {
        disc = disc+5;
    }
    ppr = (price) * (tax/100.000);
    ppr = price + ppr;
    totalt = (ppr*rooms)*(disc/100.0000);
    total = ppr*rooms;
    totalt= total-totalt;
    cout << "the cost of renting one room (with tax)"<< ppr << "$"<< endl;
    cout << "the discount on each room " << disc<< "%"<< endl;
    cout<< "the number of rooms booked "<< rooms<<endl;
    cout<<"the number of days the rooms are booked "<< days<<endl;
    cout<<"the total cost of the rooms "<< total<<"$"<< endl;
    cout<< "Tax "<< tax<<"%"<<endl;
    cout<< "Total biing amount (with disc)is "<<totalt<<"$";
}