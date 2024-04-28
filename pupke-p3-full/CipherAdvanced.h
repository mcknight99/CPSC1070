#ifndef CIPHERADVANCED_H
#define CIPHERADVANCED_H
#include "Cipher.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility> //for pairs
#include <algorithm>

class CipherAdvanced: public Cipher {
public:

  //takes in a string and tries to find the most reasonable decoded phrases
  void unknownMultiWordScramble(std::string scramble);

  //makes a words file that is shorter --> filters non alphabet & shorter than 3 char entries --> into linesFiltered vector
  static void filterWordsFile();

  //find how many words from the dict are in the string (excludes rest of the string if text doesn't start with a word)
  //countWords replaces charsUsed to also return how many chars were used in the text to make words
  static int countWords(const std::string text, int& charsUsed);

  //find target in sorted vector words
  static bool binarySearch(std::string target, const std::vector<std::string>& words);
  
  //private:

  //storage for filtered words document to binary search through
  static std::vector<std::string> linesFiltered;
};


#endif
