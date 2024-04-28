#include <iostream>
#include <string>
#include "HenryBot.h"


HenryBot::HenryBot(){
  mouth = "Hello, world!";

}


HenryBot::HenryBot(std::string inString){
  mouth = inString;

}

HenryBot::~HenryBot(){
  std::cout<<"Henry exploded!"<<std::endl;

}


//:: scope resolution operator

void HenryBot::setString(std::string inString) {
  mouth = inString;

}

void HenryBot::speak() {
  std::cout<<"HenryBot says "<<mouth<<std::endl;

}
