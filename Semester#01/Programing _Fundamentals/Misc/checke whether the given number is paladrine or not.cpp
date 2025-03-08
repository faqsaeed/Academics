#include <iostream>
using namespace std;
int main()
{
    int a,b=0,c=0,og;
    cout<<"Enter a number";
    cin>>a;
    if(a/10==1){
    cout <<"It is a paadrine numbr";
    return(0);
}
    while(a>0)
    {
        if(a/10==a%10)
        {
            b++;
        }
        c++;
        a=a/10;
}
if(b==c)
{
    cout <<"It is a paadrine numbr";
}
else{
    cout <<"It is not a paadrine numbr";
}
}