#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;



int main() {
  double temp;
  double temp2;
  cout << "Temperature in C: ";
  cin >> temp;
  temp2 = (temp*9/5)+32;
  cout << temp << "C = " << temp2 << "F\n";


}
