#include <iostream>
#include <string>
#include "HenryBot.h"

using namespace std;

int main() {
  HenryBot one;

  one.speak();

  HenryBot * henryPtr;

  henryPtr = new HenryBot("I will destroy HenryBot #1");
  (*henryPtr).speak();
  delete henryPtr;

  HenryBot* henryPtr2;
  henryPtr2 = new HenryBot("I like turquoise.");

  henryPtr2->speak();

  delete henryPtr2;

}
