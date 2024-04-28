#include <iostream>

using namespace std;

void aFunction();

int main (void) {
  aFunction();

  int phoneNumbers[10] = {8,6,4,8,6,7,5,3,0,9};
  int * arrayPointer = phoneNumbers;
cout<<"1*arrayPointer = "<<*arrayPointer<<endl;

  *arrayPointer +=3;
cout<<"2*arrayPointer = "<<*arrayPointer<<endl;

  *(arrayPointer+3)+=3;
  cout<<"3*arrayPointer = "<<*(arrayPointer+3)<<endl;

  cout<<"4*arrayPointer = "<<*arrayPointer<<endl;

  for(int i = 0; i<10; i++) {
    cout<<phoneNumbers[i]<<", ";
  }
  cout<<endl;
  int x;
  x = *arrayPointer + 5;
  cout<<"x is "<<x<<endl;
  return 0;
}

void aFunction(){
  int x[] = {10,20,30,40};
  int p = x[2];
  int q = x[1];
  int r = ++q;
  cout<<(p+1)<<endl;
  cout<<(p-1)<<endl;
  cout<<q<<endl;
  cout<<r<<endl;
  for(int i = 0; i<4; i++) {
    cout<<x[i]<<", ";
  }
  cout<<endl;
}
