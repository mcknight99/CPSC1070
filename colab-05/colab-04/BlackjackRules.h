#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "AnalyzeHand.h"

class BlackjackRules: public AnalyzeHand{
public:
  //implement the undeclared isWon function from AnalyzeHand based on the rules of blackjack
  //the sum of the cards within the hand is less than 21, assume aces are counted as 1
  bool isWon();

  //identical constructor calling AnalyzeHands constructor
  BlackjackRules(const std::vector<Card>& cards);
};

#endif
