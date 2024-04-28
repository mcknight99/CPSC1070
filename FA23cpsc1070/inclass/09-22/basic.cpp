#include <iostream>
using namespace std;

int main() {
  int a, b;
  a=6;
  b=a++; //return the variable then increment
  cout<<"a="<<a<<",b="<<b<<endl;

  int c = 13;
  if((c>a) || (a>b) && (c>b)) {
    cout<<"Henry is promoted..."<<endl;
  } else {
    cout<<"Henry is fired!"<<endl;
  }
}
