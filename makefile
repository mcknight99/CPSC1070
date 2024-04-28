compile:
	g++ Card.cpp -c -Wall
	g++ AnalyzeHand.cpp -c -Wall
	g++ BlackjackRules.cpp -c -Wall
	g++ PokerRules.cpp -c -Wall
	g++ Driver.cpp -Wall -o "deal.out"

run:
	./deal.out 0

run1:
	./deal.out 1

clean:
	rm *.o

edit:
	emacs Driver.cpp

hand:
	emacs AnalyzeHand.cpp AnalyzeHand.h

jack:
	emacs BlackjackRules.cpp BlackjackRules.h

poker:
	emacs PokerRules.cpp PokerRules.h
