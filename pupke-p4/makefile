#Sam Pupke
#CPSC 1070
#Project 4
#Dec 4 2023

compile:
	echo #################################################################################################################################################################################################
	gcc PhoneNum.c -c -Wall
	gcc Project-4.c PhoneNum.o -Wall -o "PhoneNum.exe"

run:
	./PhoneNum.exe input1.txt output1.txt

clean:
	rm *.o

edit:
	emacs PhoneNum.h PhoneNum.c

driver:
	emacs Project-4.c

file:
	vi makefile

runl:
	./PhoneNum.exe input2.txt output2.txt -l

runh:
	./PhoneNum.exe input1.txt output1.txt -h

runlh:
	./PhoneNum.exe -h input2.txt -l output2.txt

runhl:
	make runlh

