//Sam Pupke
//CPSC 1070
//11 Nov 2023

#include "Cipher.h"

//default constructor that sets the key to "cpsc"
Cipher::Cipher() {
  std::string key="cpsc"; //need a char queue
  char* keyPtr = &key[0];
  setCipher(4, keyPtr);
}

//overloaded constructor which sets the key
Cipher::Cipher(int sizeIn, char* keyIn) {
  setCipher(sizeIn, keyIn);
}

//take in the repeating key where int is the size of the array
void Cipher::setCipher(int sizeIn, char* keyIn) {

  for(int i = 0; i<sizeIn; i++) {
    unmodifiedQueue.enqueue(*(keyIn+i));
  }
  cipherQueue=unmodifiedQueue;
  cipher = keyIn;
  cipherSize = sizeIn;
}

//to get back the key
char* Cipher::getCipher() {
  return cipher;
}

//to send in a string to encode and returns the encoded string
std::string Cipher::encodeMessage(std::string in) {
  std::string out = "";
  for(int i = 0; i<static_cast<int>(in.length()); i++) {
    char shift = in[i];
    shift = letterShift(shift, cipherQueue.cycle(), false); //shift each char in the instring by the cipherQueue
    out+=shift;
  }
  cipherQueue=unmodifiedQueue;//have to reset after messing with the cipher queue
  return out;
}


//to send in a string to decode and returns the decoded string
std::string Cipher::decodeMessage(std::string in) {
  std::string out = "";
  for(int i = 0; i<static_cast<int>(in.length()); i++) {
    char shift = in[i];
    shift = letterShift(shift, cipherQueue.cycle(), true); //same code as encode except for opposite direction
    out+=shift;
  }
  cipherQueue=unmodifiedQueue; //have to reset after messing with the cipher queue
  return out;
}

//shifts x, by y, in the direction determined by reverse (true in reverse, false in forward)
char Cipher::letterShift(char x, char y, bool reverse) {
  char out = 0;
  int xint = static_cast<int>(x); //prevent char storage type overflow
  int yint = static_cast<int>(y);
  yint-=96; //lowercase chars range from 97 to 122. Subtracting 96 gives us a range of 1 to 26, making the operations much nicer to shift up and down on the x.
  xint+=reverse?-yint:yint; //where all the magic happens- if reverse is true, y will become negative and will add a negative y. if reverse is false, y will stay positive and will add a positive y.
  
  while(xint<97) { //loop back around instead of going outside of the lowercase char lower range
    xint+=26;
  }
  while(xint>122) {//loop back around instead of going outside of the lowercase char upper range
    xint-=26;
  }
  out=static_cast<char>(xint);
  return out;
}


//prints the key in numerical format
void Cipher::printNumericalFormat() {

  for(int i = 0; i<cipherSize; i++) {
    std::cout<<*(cipher+i)-96<<", ";
  }
  std::cout<<std::endl;
}

//turns any input string into match only lowercase chars
std::string Cipher::inputValidation(std::string in) {
  std::string out = "";
  for(int i = 0; i<static_cast<int>(in.length()); i++) {
    char letter = in[i];
    if(64<letter && letter<91) {
      letter+=32; //lowercase letters are 32 places higher than uppercase letters in char ints
    }
    if(96<letter&&letter<122) { //lowercase letters range from 97-122, if anything else is in here it should not be added to the key
      out+=letter;
    }
  }
  return out;
}
