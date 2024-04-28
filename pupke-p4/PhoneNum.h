//Sam Pupke
//CPSC 1070
//Project 4
//Dec 4 2023

#ifndef PHONENUM_H
#define PHONENUM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //for isdigit() and isalpha()

//type specifies whether we are 'd' (converting from digits to letters) or 'l' (converting from letters to digits)
//d --> fileIn = digits, fileOut = letters
//l --> fileIn = letters, fileOut = digits
void conversionT9(FILE* fileIn, FILE* fileOut, char type);

//will convert the given set of digits into a word through the T9 process
//the digits must be given as a C-style string with a null character at the end
//example: "222-666-3-444-66-4" --> "coding"
//you should dynamically allocate the array for the return pointer //////////////////////// IMPORTANT
char* toWord(char* digits);

//will convert a character array that makes up a word into a set of digits
//example: "coding" --> "222-666-3-444-66-4"
//you should dynamically allocate the array for the return pointer //////////////////////// IMPORTANT
char* toDigits(char* word);

//gets the next line of chars from the file and returns a pointer to a C-style* string
//* I assume the X-style in the project file is a typo and means a c-style string - why does this doc have so many typos when they are so worried about consistency for us
//you should dynamically allocate the array for the return pointer //////////////////////// IMPORTANT
char* getNextChars(FILE* fileIn);

//find textonyms, which are any set of words that share the same numeric combination as another, using the Linux dictionary for the words
//given an extra credit word, prints out all the possible textonyms of the word
//must have this prototype for extra credit
void textonymFind(char* word);

//returns a digit as a char from an alphabetical char in
char charToNum(char in);

#endif