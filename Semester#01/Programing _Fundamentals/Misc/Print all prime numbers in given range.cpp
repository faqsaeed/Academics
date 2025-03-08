#include <iostream>
using namespace std;
int main()
{
    int min=1, max=0, sum, prime, check=0, count=0;
    while(min>=max || min<0)
    {
    cout <<"Enter lower and upper limit respectivey";
    cin>>min>>max;
    }
    if(min==1)
    {
        min++;
    }
    else if(min==2)
    {
        cout<<"2"<<endl;
        min++;
        sum=2;
        count++;
    }
    while(min<=max)
    {
        for(int i=2; i<min;i++)
        {
            if(min%i==0)
            {
                check++;
            }
        }
        if(check==0){
            cout<<min<<endl;
            sum=sum+min;
            count++;
        }
        min++;
        check=0;
    }
    cout<<"There are total "<<count<<" prime numbers within the range "<<endl<<"and their sum is "<<sum;

}