#ifndef HENRY_H
#define HENRY_H
#include <string>

class HenryBot{
 private:
  std::string mouth;

 public:
  HenryBot();
  HenryBot(std::string);
  ~HenryBot();

  void setString(std::string);
  void speak();

};

#endif
