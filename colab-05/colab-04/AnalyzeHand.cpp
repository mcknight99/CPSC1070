//Samuel Pupke
//CPSC 1071: 010
//A++
//20 Nov 2023
#include "AnalyzeHand.h"

//constructor with a vector of cards as a parameter and computers the number of cards in the hand
AnalyzeHand::AnalyzeHand(const std::vector<Card>& cards) {
  hand = cards;
  numOfCards = cards.size();
}


//tostring function that returns a string of the cards within the hand
std::string AnalyzeHand::toString() {
  std::string out = "[";
  for(int i = 0; i<static_cast<int>(hand.size()); i++) {
    out+=hand[i].toString(); //turns each card to a string and adds it to the out string
    out+=", ";
  }
  out+="]";
  return out;
}
