#ifndef REGISTER_H
#define REGISTER_H
#include <vector> //vectors
#include <string> //strings
#include <iostream> //terminal io
#include <fstream> //input and output to files
#include <sstream> //input string stream for string buffer -> string object (cplusplus.com)
#include <iomanip> //formatting the output
#include <limits> //input validation limiting
#include <cctype> //tolower function

class Register{

public:
  Register();
  std::string getFileName(); //prompt the user for the name of the file and returns that as a string
  void setFileName(std::string); //set the class' private variable to a filename sent into the function
  bool processTransaction(); //driver for Register and is used to call getFileName, setFileName, readFromFile, and printFile. returns true if completes successfully, false otherwise
  bool readFromFile(); //use the internal private filename to read through the input file and populate the classes' vectors to store information. return true if file is opened and read successfully, otherwise false
  void printFile(); //print out the transactions in a neatly formatted table

private:
  std::string fileName;
  std::vector<std::vector<std::string>> fileInput;
  std::vector<std::string> dates;
  std::vector<std::string> types;
  std::vector<std::string> locations;
  std::vector<std::string> amounts;
  enum Transactions {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
  std::string toTitleCase(std::string stringIn);
  std::string formatMoney(std::string stringIn);
  
  //this ended up being more work than it was worth
  //std::vector<enum> enumeratedTypes; //where the types are going to be stored as enums instead of strings
  //enum Transactions {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER}; //enumerating the types
  //std::vector<std::string> TransactionsList = {"RESTAURANT", "MERCHANDISE", "UTILITY", "COFFEESHOP", "AUTOMOTIVE", "DEPOSIT", "OTHER"}; //making two vectors to match with each other from string vs enum
  //std::vector<enum> enumTransactions = {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
};//could be done with an array but the find of the vector is so nice

#endif