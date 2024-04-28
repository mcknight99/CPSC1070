//Sam Pupke
//CPSC 1070
//Project 4
//Dec 4 2023

#include "PhoneNum.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //tolower()

/*
Academic Honesty Statement
This assignment was completed with no outside help or resources
No Non-TA resources ere used to create code 
*/

int main(int argc, char* argv[]) {
  textonymFind("call");
  textonymFind("shop");
  textonymFind("file");
  textonymFind("type");
  textonymFind("hot");
  textonymFind("cold");
  textonymFind("home");
  textonymFind("swim");
  textonymFind("house");
  textonymFind("space");
  textonymFind("outlet");
  textonymFind("soon");
  textonymFind("test");
  int i;
  char* fileIn;
  char* fileOut;
  int flagL = 0; //bool for if flagL was included in the arg
  int flagH = 0;
  int files = 0; //not really a true "file" counter, moreso just counting the non-flag args making sure the command line is being used properly
  for(i = 1; i<argc; i++) { //i starts at 1 to ignore the executable
    if(argv[i][0]=='-') { //if it starts with a hyphen then it should be a flag
      if(tolower(argv[i][1])=='l') {
	flagL=1;
      } else if(tolower(argv[i][1])=='h') {
	flagH=1;
      } else {
	printf("flag %s not recognized, skipping and continuing\n", argv[i]);
      }
    } else { //else it should be one of the two files, an input file or an output file
      if(files==0) {
	fileIn = argv[i];
      } else if(files==1) {
	fileOut = argv[i];
      } else {
	printf("too many non-flag arguments, there should only be two: an input file and an output file\n");
      }
      files++;
    }
    
  }

  if(flagH==1) {
    /*
    printf("Usage of PhoneNum:\n");
    printf("$ executableName.exe <inputFile> <outputFile> <optional flags>\n");
    printf("Default use cases invlove the <inputFile> containing sequences of T9 presses whose conversion to words happens in the <outputFile>\n");
    printf("\nThese optional flags can be included in the command line:\n");
    printf("-l : flips the <inputFile> to be words or phreases that will be translated into T9 presses that is converted to the <outputFile>\n");
    printf("-h : brings up a short help menu (can be seen in Readme.txt as well)\n");
    printf("\nSample Usage:\n");
    printf("$ ./PhoneNum.exe input1.txt output1.txt\n");
    printf("$ ./PhoneNum.exe input2.txt -L output2.txt\n\n");
    */ //personally i like this -h better than the provided one and i didnt know about the provided one until i went to turn it in so nyeh
    printf("PhoneNum T9 Conversion Tool. Usage:\n");
    printf("PhoneNum.exe <input file> <output file> [-L]\n");
    printf("-L Sets input type as letters instead of digits\n"); //also seriously can we get some sort of consistency because there was definitely MORE spaces in the CLA example but no spaces in GS between the hyphen and flag
    printf("-h To get help\n\n\n");
  } 

  if(files==2) {
    FILE* inFile = fopen(fileIn, "r");
    FILE* outFile = fopen(fileOut, "w"); //write mode overwrites an old edition which is pretty interesting
    if(inFile == NULL) {
      printf("no such input file exists, cancelling T9\n");
    } else {
      char conversionType = '\0';
      if(flagL==1) {
	conversionType='l';
      } else {
	conversionType='d';
      }//end if else flagL
      conversionT9(inFile, outFile, conversionType);
    }
  }//end if files==2

  if(files==0 && flagH!=1) {
    printf("No input file given\nNo output file given\nUse -h to get help\n\n\n");
  }
  if(files==1 && flagH!=1) {
    printf("No output file given\nUse -h to get help\n\n\n");
  }
  
}
