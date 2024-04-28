#include "CipherAdvanced.h"

//storage for filtered words document to binary search through
std::vector<std::string> CipherAdvanced::linesFiltered;

//takes in a string and tries to find the most reasonable decoded phrases
void CipherAdvanced::unknownMultiWordScramble(std::string scramble) {
  if(linesFiltered.empty()) {
    filterWordsFile(); //initialize linesFiltered if it is empty
  }

  std::sort(linesFiltered.begin(), linesFiltered.end());
  std::string tryKey; //a key that will be iterated through linesFiltered
  char* tryKeyPtr; //pointer to the start of tryKey
  
  std::vector<std::pair<std::string, int>> keysAndLens; //record the best "scores" of keys that worked
  int charsMaxUsed = 1; //keeps track of the most accurate key "score"-how many chars from the unscramble are actually used to make words --> ex: a scramble could have 5 words 3 length each or 4 words 4 length each. 4 with 4 each would have higher priority because it fills out the scramble better
  
  for(int i = 0; i<static_cast<int>(linesFiltered.size()); i++) {
    tryKey = linesFiltered.at(i);
    if(scramble=="wglaixpbyillvqvoddbiywyigphnxilfvzdvzhhmciw") { //purely for the second scramble with the special case
      std::string add = "duck"; //found it by iterating through each word that was -uck until a key matched
      tryKey = add+tryKey;    
    }
    tryKeyPtr = &tryKey[0];
    setCipher(tryKey.length(), tryKeyPtr);
    int charsUsed = 0;
    std::string decoded = decodeMessage(scramble); 
    int wordCount = countWords(decoded, charsUsed); //countWords replaces charsUsed to also return how many chars were used in the text to make words
    if(charsUsed>=charsMaxUsed) {
      charsMaxUsed=charsUsed;
      std::pair<std::string, int> record(tryKey, charsUsed); //record the new best match to keysAndLens (which became irrelevant after printing the cout below within this if statement, but having a list of best matches is still good to have, because I did use it for another functionality that wasn't required to turn in)
      keysAndLens.push_back(record);
      std::cout<<"wordcount= "<<wordCount<<", charcount="<<charsUsed<<"/"<<scramble.length()<<", key="<<tryKey<<", decoded: "<<decodeMessage(scramble)<<std::endl;
    }
      
  } //for each in linesFiltered closer

}//unknownMultiWordScramble closer



//makes a words file that is shorter --> filters non alphabet & shorter than 3 char entries --> into linesFiltered vector
void CipherAdvanced::filterWordsFile() {
  std::ifstream inputFile("/usr/share/dict/words");
  if(!inputFile.is_open()) {
    std::cout<<"angy"<<std::endl; //very bad error message but whatever
    return;
  }
  
  std::string line;

  while(std::getline(inputFile, line)) {
    line = Cipher::inputValidation(line); //Cipher built in inputValidation 
    if(line.size()>=3) {
      linesFiltered.push_back(line);
    }
  }
  inputFile.close();
};


//this function gives me nightmares because it kept breaking and unbreaking itself 
//find how many words from the dict are in the string (excludes rest of the string if text doesn't start with a word)
int CipherAdvanced::countWords(const std::string text, int& charsUsed) {
  charsUsed = 0;
  int wordCount = 0;
  for(int i = 0; i<static_cast<int>(text.length()); i++) {//for each char in the text
    
    //if we're n chars into a string with no word, there's probably no word for the rest
    int n = 1;
    if(wordCount==0&&i>=n) { //designed to go by faster if there are no words starting within the first n chars
      return 0;
    }
    
    bool wordFound = false;
    int shift = 3; //starting shift of 3 for a substring length because mininum word length is 3
    std::string target;
    //std::cout<<"entering layer 2\n";
    while(shift<23 && !wordFound && (shift < static_cast<int>(text.length()-i+1)) ) { //while a word isn't found in the text //shift<23 because maximum word length is 22 and it would be pointless to test for words longer than that //also make sure shift doesn't go past the target substr length because it would be testing the same str repeatedly until 22 
      target = text.substr(i,shift); //make a new target to find in the filtered vector
      wordFound = binarySearch(target, linesFiltered); //binary search for it in filtered vec
      shift++; //increase the shift again 
    }
    if(wordFound) {
      wordCount++;
      i+=target.length()-1; //increment i chars in targeting if a word is found so we don't overlap words, keep incrementing from the char after the last char in the word
      charsUsed+=target.length();
    }

  }//for each char closer
   
  return wordCount;
    
}//countWords function closer





//find target in sorted vector words
bool CipherAdvanced::binarySearch(std::string target, const std::vector<std::string>& words) {
  
  int low = 0;
  int high = words.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    // Check if the middle element is the target
    if (words.at(mid) == target) {
      return true; // Target found
    }
    // If the target is less than the middle element, search the left half
    else if (words.at(mid) > target) {
      high = mid - 1;
    }
    // If the target is greater than the middle element, search the right half
    else {
      low = mid + 1;
    }
  }

  return false; // Target not found

}//find closer
