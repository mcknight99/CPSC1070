#include <iostream>
#include "overload.h"

using namespace std;

int main() {
  //exam question
  //friend functions have access to _______
  //private parts
  
  cout<<"testing our operator overloading"<<endl;

  Length first(0), second(0), third(0);
  int f, i;

  cout<<"enter a height in feet and inches: ";
  cin>>f>>i;

  first.setLength(f,i);

  cout<<"enter a height in feet and inches: ";
  cin>>f>>i;

  second.setLength(f,i);

  cout<<"enter a height in feet and inches: ";
  cin>>f>>i;

  third.setLength(f,i);


  //cout<<"the total height is: ";
  cout<<"is henry taller than dr plaue?";
  if(first<second) {
    cout<<"yes"<<endl; 
  } else {
    cout<<"no"<<endl;
  }


  cout<<"goodbye world"<<endl;
}
