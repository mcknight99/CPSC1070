#include <iostream>
using namespace std;

int main() {
  cout<<"Starting a scope demo!"<<endl;
  int henry=0;
  cout<<"1.0: " <<henry<<endl;
  henry = 13;
  {
    cout<<"2.0: " <<henry<<endl;
    int henry = 666; //SCOPE OF THIS VARIABLE IS DIFFERENT FROM THE MAIN HENRY
    cout<<"2.1: " <<henry<<endl;
  }
  cout<<"3.0: "<<henry<<endl;

  
  cout<<"Goodbye,world!";

}
