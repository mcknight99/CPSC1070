#ifndef REGISTER_H
#define REGISTER_H

#include <string>

class Register{

 public:
  Register();
  std::string getFileName();
  void setFileName(std::string);
  bool processTransaction();
  bool readFromFile();
  void printFile();


 private:


};

#endif
