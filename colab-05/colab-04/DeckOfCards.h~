//Sam Pupke
//CPSC 1071: 010
//A++
//5 Nov 2023

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "Card.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>

class DeckOfCards{

public:
  
  //default constructor for a deck of cards
  //stores the cards to the vector "deck"
  //in the order of Hearts, Diamonds, Clubs, Spades
  //as well as Ace, 2->10, J, Q, K
  DeckOfCards();

  //returns a boolean of true if there are more cards in the deck
  //returns false if there are no more cards in the deck
  bool moreCards();

  //returns the Card at the top of the deck vector
  //removes the Card from the deck vector
  Card dealCard();

  //prints next card to console in shorthand
  void peekNextCard();

  //prints remaining deck to console in one line in shorthand
  void peekDeck();

  //swaps a pair of randomly selected cards an int@count amount of times
  //default count is 100 swaps (defined in DeckOfCards.h)
  void shuffle(int count = 100);


private:
  std::vector<Card> deck;
};

#endif
