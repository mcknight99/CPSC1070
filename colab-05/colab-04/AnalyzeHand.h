//Samuel Pupke
//CPSC 1071: 010
//A++
//20 Nov 2023
#ifndef ANALYZE_H
#define ANALYZE_H
#include "Card.h"
#include <vector>
#include <iostream>

class AnalyzeHand{
 public:
  
  //constructor with a vector of cards as a parameter and computers the number of cards in the hand
  AnalyzeHand(const std::vector<Card>& cards);

  //tostring function that returns a string of the cards within the hand
  std::string toString();

  //abstract function isWon() that returns true if the game is won or false if the game is not won
  virtual bool isWon() = 0;

  //destructors are good for abstract classes
  virtual ~AnalyzeHand() {}

protected:
  int numOfCards; //amount of cards in the hand //gonna admit i completely forgot this variable existed when i was writing code to iterate through hand but i also trust directly accessing the size every time i need to call hand 
  std::vector<Card> hand; //vector array of cards is the hand 

};

#endif
