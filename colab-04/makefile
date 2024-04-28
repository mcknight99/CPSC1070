compile:
	g++ Card.cpp -c
	g++ DeckOfCards.cpp -c
	g++ Driver.cpp Card.o DeckOfCards.o -Wall -o "Driver.out"

run:
	./Driver.out

clean:
	rm *.out

edit:
	emacs Driver.cpp


card:
	emacs Card.cpp Card.h


deck:
	emacs DeckOfCards.cpp DeckOfCards.h
