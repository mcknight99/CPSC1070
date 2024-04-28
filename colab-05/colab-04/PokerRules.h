//Samuel Pupke
//CPSC 1071: 010
//A++
//20 Nov 2023
#ifndef POKER_H
#define POKER_H
#include "AnalyzeHand.h"
#include <utility> //pairs

class PokerRules: public AnalyzeHand{
 public:
  //implement the undeclared isWon function which will check if the hand contains: pair, two pairs, three of a kind, four of a kind, flush, or straight. does not need to check if the hand has 5 cards in it
  bool isWon();
  bool pair(); //returns true if two cards have the same face value
  bool twoPairs(); //returns true if two pairs are found
  bool threeOfAKind(); //returns true if there are 3 cards of the same face value
  bool fourOfAKind(); //returns true if there are 4 cards of the same face value 
  bool straight(); //returns true if there are 5 cards in sequential order in face value
  bool flush(); //returns true if there are 5 cards of all the same suit
  PokerRules(const std::vector<Card>& cards); //pokerrules constructor implementing analyzehands constructor

private:
  void initVOI(); //initialize vectorOfInstances
  std::vector<std::pair<int, int> > vectorOfInstances; //the first int is the face value, the second int is the instance count of that face value. made the face value counting several times easier
};

#endif
