//Samuel Pupke
//CPSC 1071: 010
//A++
//20 Nov 2023
#include "BlackjackRules.h"

//implement the undeclared isWon function from AnalyzeHand based on the rules of blackjack
//the sum of the cards within the hand is less than 21, assume aces are counted as 1
bool BlackjackRules::isWon() {

  int sum = 0;
  for(int i = 0; i<static_cast<int>(hand.size()); i++) {
    if(hand[i].face>9) {//because they want us to start as ace=0, faces start at 10
      //all face values are 10 in blackjack --> i hate that we are referring to values of cards as faces when there is already the term "face" for face cards Jack, Queen, King (and joker i guess)
      sum+=10;
    } else {
      sum+=hand[i].face+1;
    }
  }

  return (sum<=21);

}

//identical constructor calling AnalyzeHands constructor
BlackjackRules::BlackjackRules(const std::vector<Card>& cards) : AnalyzeHand(cards) {};
