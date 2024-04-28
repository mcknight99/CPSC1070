//Sam Pupke
//CPSC 1070
//11 Nov 2023

#ifndef CIPHER_H
#define CIPHER_H

#include "Queue.h"
#include <string>
#include <iostream>

//Note: whitespace, numbers, and punctuation should be stripped out. "Hello World 2 Go!" --> "helloworldgo"

class Cipher{

public:
  //default constructor that sets the key to "cpsc"
  Cipher();
  //overloaded constructor which sets the key
  Cipher(int, char*);
  //take in the repeating key where int is the size of the array
  void setCipher(int, char*);
  //to get back the key
  char* getCipher();
  //to send in a string to encode and returns the encoded string
  std::string encodeMessage(std::string in);
  //to send in a string to decode and returns the decoded string
  std::string decodeMessage(std::string in);
  //shifts x, by y, in the direction determined by reverse (true in reverse, false in forward)
  static char letterShift(char x, char y, bool reverse);

  //prints the key in numerical format
  void printNumericalFormat();

  //turns any input string into match only lowercase chars
  static std::string inputValidation(std::string in);

  private:
  char* cipher;
  int cipherSize;
  Queue<char> cipherQueue;
  Queue<char> unmodifiedQueue;
};

#endif
