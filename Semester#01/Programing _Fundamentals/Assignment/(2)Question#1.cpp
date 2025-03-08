#include <iostream>
using namespace std;

int main() 
{
  string n, c, cl, pr, an, p;
  int a;
  cout << "Enter your name ";
  cin>>n;
  cout<< endl << "Enter your age ";
  cin>>a;
  cout<< endl<<"what's the name of your city ";
  cin>> c;
  cout<<endl<< "enter the name of your college ";
  cin>> cl;
  cout<<endl<<"Enter your profession ";
  cin>>pr;
  cout<<endl<<"Enter a type of animal ";
  cin>>an;
  cout<<endl<<"Enter your pet name";
  cin>> p;
  cout<< endl;
   cout<< "There once was a person named " <<n<< " who lived in " << c <<". At the age of "<<a<< ", " <<n<< " went to college at "<< cl <<". "<<n<<" graduated and went to work as "<<pr<<". Then "<<n<<" adopted a(n)"<<an<<" named "<<p<<". They both lived happily ever after!";
}

