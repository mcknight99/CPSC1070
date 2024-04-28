# Samuel Pupke
# CPSC 1071: 010
# A++
# 20 Nov 2023

compile:
	g++ Card.cpp -c -std=c++98
	g++ DeckOfCards.cpp -c -std=c++98
	g++ AnalyzeHand.cpp -c -std=c++98
	g++ BlackjackRules.cpp -c -std=c++98
	g++ PokerRules.cpp -c -std=c++98
	g++ Dealer.cpp Card.o DeckOfCards.o AnalyzeHand.o BlackjackRules.o PokerRules.o -Wall -o "deal.out" -std=c++98

run:
	./deal.out 0

run0:
	./deal.out 0

run1: 
	./deal.out 1

clean:
	rm *.out

edit:
	emacs Dealer.cpp

card:
	emacs Card.h Card.cpp

deck:
	emacs DeckOfCards.h DeckOfCards.cpp

file:
	vi makefile

analyze:
	emacs AnalyzeHand.h AnalyzeHand.cpp

jack:
	emacs BlackjackRules.h BlackjackRules.cpp

poker:
	emacs PokerRules.h PokerRules.cpp
