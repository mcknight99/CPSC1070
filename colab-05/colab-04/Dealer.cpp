//Sam Pupke
//CPSC 1071: 010
//A++
//5 Nov 2023

#include <iostream>
#include "Card.h"
//#include "DeckOfCards.h" //I ended up not using deckofcards because the vectors were what we were required to use, but if the colab continues past this then I assume it will be used, so I kept it in the "branch"
#include "AnalyzeHand.h"
#include "BlackjackRules.h"
#include "PokerRules.h"
#include <cstdlib> //std::atoi

using namespace std;

int main(int argc, char* argv[]) {
  if(argc==2) {
    if(atoi(argv[1])==0) { //blackjack
      cout<<"\n******* Welcome to Blackjack Rules *******\n\nWe are checking the Hand:\n";
  
      vector<Card> blackjackCards;
      blackjackCards.push_back(Card(0,0));
      blackjackCards.push_back(Card(11,0));
      blackjackCards.push_back(Card(10,0));

      AnalyzeHand* blackjackHand = new BlackjackRules(blackjackCards);
  
      cout<<"\t"<<blackjackHand->toString();
      cout<<"\n\n...Checking\n\n";
      cout<<(blackjackHand->isWon()?"This is a Winning hand!\n\n":"This is a Losing hand!\n\n");

      delete blackjackHand;
    } else if(atoi(argv[1])==1) { //poker  
      cout<<"\n******* Welcome to Poker Rules *******\n\nWe are checking the Hand:\n";
  
      vector<Card> pokerCards;
      /*
      pokerCards.push_back(Card(8,0));
      pokerCards.push_back(Card(1,0));
      pokerCards.push_back(Card(10,0));
      pokerCards.push_back(Card(11,0));
      pokerCards.push_back(Card(1,1));
      */
      pokerCards.push_back(Card(8,0));
      pokerCards.push_back(Card(1,0));
      pokerCards.push_back(Card(10,0));
      pokerCards.push_back(Card(11,0));
      pokerCards.push_back(Card(2,0));
      
      AnalyzeHand* pokerHand = new PokerRules(pokerCards);

      cout<<"\t"<<pokerHand->toString();
      cout<<"\n\n...Checking\n\n";
      cout<<(pokerHand->isWon()?"This is a Winning hand!\n\n":"This is a Losing hand!\n\n");

      delete pokerHand;

    }
  }
}
