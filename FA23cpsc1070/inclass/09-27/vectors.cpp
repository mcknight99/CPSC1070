#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> henry;

  for(int i = 0; i<13; i++) {
    henry.push_back(i);
  }

  cout<<"The size of henry is "<<henry.size()<<endl;
  cout<<"The capacity of henry is "<<henry.capacity()<<endl;
  henry.resize(4);

  cout<<"The size of henry after resizing is "<<henry.size()<<endl;
  
  cout<<"The capacity of henry is "<<henry.capacity()<<endl;

  for(int i = 0; i<henry.capacity(); i++) {
    cout<<"";
  }

  
  cout<<"Is henry empty? " <<henry.empty()<<endl;
  cout<<"Goodbye vector world"<<endl;
}
