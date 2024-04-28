compile:
	g++ Register.cpp -c -Wall
	g++ Retirement.cpp -c -Wall
	g++ Loan.cpp -c -Wall
	g++ Clementine.cpp Register.o Retirement.o Loan.o -Wall -o "Clementine.out"

run: 
	./Clementine.out

clean:
	rm *.out

edit:
	emacs Clementine.cpp
