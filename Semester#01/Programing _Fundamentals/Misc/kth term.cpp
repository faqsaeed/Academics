#include <iostream>
using namespace std;
int main()
{
  int a,b,k,c,d,i;
  i=0;
  cin>> a>>b>>k;
  while (i<=k){
    c=a%10;
    d=b%10;
    a=a/10;
    b=b/10;
    if (i==k)
    {
      if (c==d)
      {
        cout << "kth term is same";
      }
      else 
      {
        cout << "kth term is not same";
      }
    }
      i++;
    }
  
}