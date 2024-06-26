//Sam Pupke
//CPSC 1071: 010
//A++
//5 Nov 2023

#ifndef CARD_H
#define CARD_H
#include <string>

class Card{

public:
  //default constructor for a card will default to an ace of hearts
  Card();

  //2 parameter constructor for a card to set the face and suit of a card
  Card(int face, int suit);

  //returns a string of the card in long hand, using the Faces[] and Suits[] string arrays
  std::string toString();

  //returns a string of the card in short hand, using the FancyFaces[] and FancySuits[] string arrays
  std::string fancyString();

  //used to have them starting at one to match with blanks but the lab requirements say they start at zero which is dumb but whatever
  enum Faces{ACE=0,DEUCE,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
  enum Suits{HEARTS=0,DIAMONDS,CLUBS,SPADES};

  

  int face;
  int suit;
  static std::string Faces[];
  static std::string Suits[];
  static std::string FancyFaces[];
  static std::string FancySuits[];

};

#endif
