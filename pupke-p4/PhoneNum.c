//Sam Pupke
//CPSC 1070
//Project 4
//Dec 4 2023

#include "PhoneNum.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //for isdigit() and isalpha()


//find textonyms, which are any set of words that share the same numeric combination as another, using the Linux dictionary for the words
//given an extra credit word, prints out all the possible textonyms of the word
//must have this prototype for extra credit
void textonymFind(char* word) {
  char wordAsNums[strlen(word)];
  //if i had a function that split between this and toDigits to turn a letter into nums that would be great but i didn't do that in the first place and i dont want to go back and rework toDigits
  int i;
  for(i = 0; i<strlen(word); i++) {
    //this is grody but whatever
    char letter = tolower(word[i]);
    wordAsNums[i] = charToNum(letter);
  }//for each letter in word closer
  wordAsNums[strlen(word)]='\0';
  FILE* inFile = fopen("/usr/share/dict/words", "r");  

  char* input = getNextChars(inFile);
  while(input!=NULL) {
    char inputAsNums[strlen(input)+1];
    for(i = 0; i<strlen(input); i++) { //turn the input dictionary line into a textonym
      char letter = tolower(input[i]);
      inputAsNums[i] = charToNum(letter);
    }
    inputAsNums[strlen(word)]='\0';
    if(strcmp(wordAsNums, inputAsNums)==0 && strlen(word)==strlen(input)) { //see if the dictionary line matches the word as a textonym
      for(i = 0; i<strlen(input); i++) {
	input[i] = tolower(input[i]); //turn the matching texto to lowercase
      }
      char wordfix[strlen(word)];
      for(i = 0; i<strlen(wordfix); i++) {
	wordfix[i] = toupper(word[i]); //turn the originl texto to uppercase
      }
      printf("%s -> %s\n", wordfix, input);
    }
    input = getNextChars(inFile);
  }
  free(input);

}

//returns a digit as a char from an alphabetical char in
char charToNum(char in) {
switch (in) {
    case 'a' : case 'b' : case 'c':
      return '2';
    case 'd' : case 'e' : case 'f':
      return '3';
    case 'g' : case 'h' : case 'i':
      return '4';
    case 'j' : case 'k' : case 'l':
      return '5';
    case 'm' : case 'n' : case 'o':
      return '6';
    case 'p' : case 'q' : case 'r' : case 's':
      return '7';
    case 't' : case 'u' : case 'v':
      return '8';
    case 'w' : case 'x' : case 'y' : case 'z':
      return '9';
    default:
      return ' ';
    }//switch closer
}//charToNum closer



//type specifies whether we are 'd' (converting from digits to letters) or 'l' (converting from letters to digits)
//d --> fileIn = digits, fileOut = letters
//l --> fileIn = letters, fileOut = digits
void conversionT9(FILE* fileIn, FILE* fileOut, char type) {
  char* input = getNextChars(fileIn);
  char* result = NULL;
  while(input!= NULL) {
    if(type=='d') {//digits to letters
      result=toWord(input);
    } else if(type=='l') { //letters to digits
      result=toDigits(input);
    } else {
      printf("Error in method conversionT9: type char is neither l nor d, will probably also throw error when freeing\n");
    }
    fprintf(fileOut, "%s\n", result); //write to file
    input = getNextChars(fileIn);     //get next line
  }//while !null closer
  free(input); //deallocate getNextChars returned str
  free(result);
} //conversionT9 closer

//will convert the given set of digits into a word through the T9 process
//the digits must be given as a C-style string with a null character at the end
//example: "222-666-3-444-66-4" --> "coding"
//you should dynamically allocate the array for the return pointer //////////////////////// IMPORTANT
char* toWord(char* digits) {
  if(strlen(digits)==1 || isalpha(digits[0])) { //for some reason they want us to return the num if its just the lone num and im also guessing to ignore any chars in it
    return digits;
  }

  //the plan is simply to reference this array for every group of digits.
  //the row is the value of the first digit after a hyphen minus two
  //the column is how many times the digit shows up minus one
  char digitToChar[8][4] = { 
			  {'a','b','c','\0'},
			  {'d','e','f','\0'},
			  {'g','h','i','\0'},
			  {'j','k','l','\0'},
			  {'m','n','o','\0'},
			  {'p','q','r','s'},
			  {'t','u','v','\0'},
			  {'w','x','y','z'}
  };

  size_t digitLen = strlen(digits);
  int i;
  int occurrences = 0;
  char out[1000];
  int outCount = 0; //unfortunately i did not think about strcat until writing toDigits but i dont want to touch this function because it was a pain to debug and would rather not go back and mess with it again
  
  for(i = 0; i<digitLen; i++) {
    
    if(digits[i]=='-') {
      //if we reach a hyphen or the end, record a new char
      //i actually have no clue why i have to subtract 48 but i saw a pattern and it worked so im not complaining just very confused
      out[outCount]=digitToChar[digits[i-1]-2-48][occurrences-1];
      occurrences=0;
      outCount++;
    } else if ( i == digitLen-1) { //if we reach the end that means we're still on a digit
      occurrences++;
      out[outCount]=digitToChar[digits[i]-2-48][occurrences-1];
      occurrences=0;
      outCount++;
    } else {
      occurrences++;
    }
  }
  out[outCount]='\0';
  //copy and pasting this code from getNextChars, has better comments there for this
  size_t len = strlen(out);
  char* result = (char*)malloc((len+1)*sizeof(char)); 
  strcpy(result, out);
  return result;

} //toWord closer









//will convert a character array that makes up a word into a set of digits
//example: "coding" --> "222-666-3-444-66-4"
//you should dynamically allocate the array for the return pointer //////////////////////// IMPORTANT
char* toDigits(char* word) {
  if(isdigit(word[0])) {  //if its a number then ignore it
    return word;
  }

  //the plan is to reverse engineer it now rather than searching the digitToChar array:
  //the char 'a' has a dec value of 97, so subtracting 97 from each char gives us the indexes to a "1d array" of "strings" (2d array of chars)
  //I could probably make the digitToChar "abc\0" etc.. but i think its more understandable how they both are right now
  char charToDigit[26][5] = {
			     "2", "22", "222",
			     "3", "33", "333",
			     "4", "44", "444",
			     "5", "55", "555",
			     "6", "66", "666",
			     "7", "77", "777", "7777",
			     "8", "88", "888",
			     "9", "99", "999", "9999"
  };

  int i;
  char out[1000];
  strcpy(out, "");
  for(i = 0; i<strlen(word); i++) {
    
    int charToInt = word[i]-97;
    char* app = charToDigit[charToInt];
    strcat(out, app);
    if(i!=strlen(word)-1) {
      strcat(out, "-");//add a hyphen if it isnt the last char
    }
    
  }

  //copy and pasting this code from getNextChars, has better comments there for this
  size_t len = strlen(out);
  char* result = (char*)malloc((len+1)*sizeof(char)); 
  strcpy(result, out);
  return result;

} //toDigits closer

//gets the next line of chars from the file and returns a pointer to a C-style* string
//* I assume the X-style in the project file is a typo and means a c-style string - why does this doc have so many typos when they are so worried about consistency for us
//you should dynamically allocate the array for the return pointer //////////////////////// IMPORTANT
char* getNextChars(FILE* fileIn) {
  char inText[100]; //hopefully no line is longer than 100 chars but if it is this can be increased

  if(fgets(inText, sizeof(inText), fileIn) != NULL) { //sets inText while making sure it isnt null

    size_t len = strlen(inText); //saw a friend use size_t when comparing a length to an int and i was mind blown that i dont have to static cast the length every time
    if(len>0 && inText[len-1]=='\n') {
      inText[len-1]='\0'; // if the last char is a newline, make it a null char
    }

    //allocate memory for the string and copy it

    char* result = (char*)malloc((len+1)*sizeof(char)); //allocate memory for the len plus the null char and cast to char*
    if(result==NULL) {
      printf("okay what in the world why did i get this error\n");
    }

    strcpy(result, inText);
    return result;
	
  }
  
  return NULL;

} //getNextChars closer
