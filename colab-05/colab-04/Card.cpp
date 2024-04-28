//Sam Pupke
//CPSC 1071: 010
//A++
//5 Nov 2023

#include "Card.h"

//having blank faces and suits allows for
//1. blank cards, can be used for things such as an error card, like the drawCard returning no cards if the deck ran out
//2. better reading within this class for referencing the string arrays without having to subtract one to match the array
std::string Card::Faces[] = {"BlankFace","Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

std::string Card::Suits[] = {"BlankSuit","Hearts", "Diamonds", "Clubs", "Spades"};

std::string Card::FancyFaces[] = {"F","A","2","3","4","5","6","7","8","9","10","J","Q","K"};

std::string Card::FancySuits[] = {"S","♥", "♦", "♣", "♠"};

//default constructor for a card will default to an ace of hearts
Card::Card() {
  face=ACE;
  suit=HEARTS;
}

//2 parameter constructor for a card to set the face and suit of a card
Card::Card(int faceIn, int suitIn) {
  face=faceIn;
  suit=suitIn;
}

//returns a string of the card in long hand, using the Faces[] and Suits[] string arrays
std::string Card::toString() {
  return Faces[face+1] + " of " + Suits[suit+1];
}

//returns a string of the card in short hand, using the FancyFaces[] and FancySuits[] string arrays
std::string Card::fancyString() {
  //return FancySuits[suit]+FancyFaces[face];
  return FancyFaces[face+1]+FancySuits[suit+1];//cant decide which looks better
}
