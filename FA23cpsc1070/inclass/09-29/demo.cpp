#include "demo.h"
#include <iostream>
using namespace std;

Demo::Demo() {
  
  cout<<"The demo constructor has been called!\n";
}

Demo::Demo(char inChar) {
  lel = inChar;
  cout<<"The demo char constructor has been called!\n";
}

Demo::~Demo() {
  cout<<"WHERE'S THE KABOOM? THERE WAS SUPPOSED TO BE AN EARTH SHATTERING KABOOM";

}

