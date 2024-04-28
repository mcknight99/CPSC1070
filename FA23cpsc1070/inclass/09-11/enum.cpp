#include <iostream>
using namespace std;

int main() {
  cout<<"Starting our eunumerated type demo"<<endl;
  
  enum Fruit {apple, grape, orange};
  cout<< "apple = " << apple << " grape = "<<grape<<endl;

  enum Fruit2 {banana = 5, cherry = 4, tomato};
  cout << "tomato =" <<tomato<<endl;
  
  
  cout<<"Goodbye world";
}
