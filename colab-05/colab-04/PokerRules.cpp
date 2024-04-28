//Samuel Pupke
//CPSC 1071: 010
//A++
//20 Nov 2023
#include "PokerRules.h"

//pokerrules constructor implementing analyzehands constructor
PokerRules::PokerRules(const std::vector<Card>& cards) : AnalyzeHand(cards) {
  initVOI();
}

//implement the undeclared isWon function which will check if the hand contains: pair, two pairs, three of a kind, four of a kind, flush, or straight. does not need to check if the hand has 5 cards in it
bool PokerRules::isWon() {
  bool out = false;
  out = pair() || twoPairs() || threeOfAKind() || fourOfAKind() || straight() || flush();
  return out;
}

//returns true if two cards have the same face value
bool PokerRules::pair() {
  bool out = false;
  //if there is a single instance in VOI with a count of 2 then there is a pair
  for(int i = 0; i<static_cast<int>(vectorOfInstances.size()); i++) {
    if(vectorOfInstances[i].second==2) {
      out=true;
    }
  }
  return out;
}

//returns true if two pairs are found
bool PokerRules::twoPairs() {
  bool out = false;
  int pairCount = 0;
  //if there are two instances in VOI with a count of 2 then there is a two pair
  for(int i = 0; i<static_cast<int>(vectorOfInstances.size()); i++) {
    if(vectorOfInstances[i].second==2) {
      pairCount++;
    }
  }
  if(pairCount==2) {
    out=true;
  }
  
  return out;
  
}

//returns true if there are 3 cards of the same face value
bool PokerRules::threeOfAKind() {
  bool out = false;
  //if there is a single instance in VOI with a count of 3 then there is a 3OAK
  for(int i = 0; i<static_cast<int>(vectorOfInstances.size()); i++) {
    if(vectorOfInstances[i].second==3) {
      out=true;
    }
  }
  
  return out;

}

//returns true if there are 4 cards of the same face value
bool PokerRules::fourOfAKind() {
  bool out = false;
  //if there is a single instance in VOI with a count of 4 then there is a 4OAK
  for(int i = 0; i<static_cast<int>(vectorOfInstances.size()); i++) {
    if(vectorOfInstances[i].second==4) {
      out=true;
    }
  }
  
  return out;

}

//returns true if there are 5 cards in sequential order in face value
bool PokerRules::straight() {
  bool out = true; //without sorting the hand, we can assume in a straight that the highest card and lowest card are separated by a value of 4 (ex. 2,3,4,5,6: 6-2=4) and that every other card will be values between those values
  int maxValue = hand[0].face;
  int minValue = hand[0].face;
  for(int i = 1; i<static_cast<int>(hand.size()); i++) {
    if(hand[i].face>maxValue) {
      maxValue = hand[i].face;
    }
    if(hand[i].face<minValue) {
      minValue = hand[i].face;
    }
  }

  if(maxValue-minValue!=4) {
    return false; //if max and min aren't separated by a value of 4, then there isnt a straight
  }
  //edge case that we have a min and max separated by 4 but have duplicate face value cards, so we need 5 single instances in VOI (ex: 4♥ 4♦ 8♣ 7♠ 6♣) //and although the isWon puts pair before straight and would catch the pair, having straight check for it anyways is good 
  //this could be done just by taking vectorOfInstances.size()==5 assuming that a poker hand is always equal to 5
  if(static_cast<int>(vectorOfInstances.size())!=5) {
    return false;
  }
  
  return out;

}

//returns true if there are 5 cards of all the same suit
bool PokerRules::flush() {
  bool out = true; //easier to disprove a flush than to prove a flush by iterating
  for(int i = 1; i<static_cast<int>(hand.size()); i++) {//starting at the second card and comparing back
    if((hand[i].suit)!=(hand[i-1].suit)) {//if the last card and the current card dont match suits
      out = false;//then a flush is disproven
    }
  }
  return out;

}

//initialize vectorOfInstances
void PokerRules::initVOI() {
  vectorOfInstances.clear();
  for(int i = 0; i<static_cast<int>(hand.size()); i++) {
    bool newFace = true;
    for(int j = 0; j<static_cast<int>(vectorOfInstances.size()); j++) {
      if(vectorOfInstances[j].first==hand[i].face) { //if the stored face [j].first matches the checking card face [i] then do not list a new instance but do add to the current instance counter
	newFace=false;
	vectorOfInstances[j].second+=1;
      }
    }
    if(newFace) {
      std::pair<int,int> newInstance(hand[i].face, 1);
      vectorOfInstances.push_back(newInstance);
    }

  }
}