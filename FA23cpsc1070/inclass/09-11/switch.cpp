#include <iostream>
using namespace std;

int main(){
  cout<<"Starting our switch demo"<<endl;
  
  char myChar = "";

  cout<<"Enter a, b, or c: ";
  cin >> myChar;

  switch (myChar) {
  case 'a': case 'A':
    cout<<"apply a here" <<endl;
    break;
  case 'b':
    cout<<"apply b here"<<endl;
    break;
  case 'c':
    cout<<"apply c here"<<endl;
    break;
  default:
    cout<<"in default case: a, b, c is not here"<<endl;
    break;
  }
  
  
  
  cout<<"goodbye, world!";
}
