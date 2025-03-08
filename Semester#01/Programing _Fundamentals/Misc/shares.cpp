#include <iostream>
using namespace std;

int main() 
{
  float a,b,c,d,e,f,g,h;
  a = 1000.0;
  b = 45.50;
  c = 56.90;
  d = a*b;
  e = a*c;
 
  g = 0.02 * d;
  h = 0.02 * e;
  f = e - d - g - h;
  
  cout <<"buying price "<< d<< "$"<<endl<<"selling price "<<e<<endl<<"commision given on buying "<<g<<endl<<"commision given on selling "<<h<<endl<<"total profit "<<f;
}