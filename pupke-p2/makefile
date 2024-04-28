# Sam Pupke
# Pizza Wars
compile:
	g++ Date.cpp -c -Wall
	g++ PizzaStore.cpp -c -Wall
	g++ PizzaWars.cpp -c -Wall
	g++ driver.cpp Date.o MysteryMachine.o PizzaStore.o PizzaWars.o -Wall -o "battle.out"

run:
	./battle.out

clean:
	rm *.out

edit:
	emacs driver.cpp

store: 
	emacs PizzaStore.h PizzaStore.cpp

wars:
	emacs PizzaWars.h PizzaWars.cpp
	echo "several wars have broken out across europe (again), thanks to you"

date:
	emacs Date.h Date.cpp

log:
	emacs log.txt
