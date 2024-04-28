//Samuel Pupke
//CPSC 1071: Section 5
//Team 3, A++
//Date: Oct 2, 2023


#include <iostream> //need to input and output to terminal
#include <limits> //need for input validation limiting
#include <cmath> //rounding
#include <iomanip> //setprecision
#include "Loan.h"
#include "Retirement.h"
#include "Register.h"

using namespace std;

//prototypes
void runMenuSystem();


int main() {
  runMenuSystem();
}


//starts text based menu to user in terminal
//case does not matter:
//E - estimate how much money an individual will have at retirement
//L - run the payoff calculator that we created in CoLab 1
//R - run the file reader for transactions
//Q - quit the program
void runMenuSystem() {
  std::cout<<"Starting Clementine Financial Bank\n";
  string choice = "  ";
  bool valid = false;
  do{
    cout<<"******* Welcome to Clementine Financial *********\n\n"; //ok fess up what goober added two extra stars to the header on the right between last and this project
    cout<<"Menu:\n";
    cout<<"\t[E] Estimate how much money at retirement\n";
    cout<<"\t[L] Loan payoff calculator\n";
    cout<<"\t[R] Run transaction classifier\n";
    cout<<"\t[Q] Quit program\n\n";
    cout<<" Enter your choice and press enter: ";
    cin>>choice;
    if(cin.good() && choice.length()==1) {
      valid=true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"\nThe provided choice was invalid! Please select again.\n\n";
    }
    
    char input = choice.at(0);//first char in the string vector because you can't pass a string through a switch, even if its only one char

    if(valid) {//prevents running the switch case, thus causing a default double print of invalid choice
      switch (input) {//switch open
      case 'E' : case 'e':
	//CODE FOR ESTIMATE OF MONEY AT RETIREMENT
	Retirement::estimateDriver();
	valid=false;
	break;
      case 'L': case 'l':
	//CODE FOR LOAN PAYOFF CALCULATOR
	Loan::paymentDriver();
	valid=false;
	break;
      case 'R' : case 'r':
	{//needed brackets for a weird jump bug for making a Register object, so i had to keep it limited to its own scopey
	  Register myReg;
	  myReg.processTransaction();
	  valid=false;
	}
	break;
      case 'Q': case 'q':
	//CODE FOR QUIT PROGRAM
	valid=true;
	break;
      default:
	cout<<"\nThe provided choice was invalid! Please select again.\n\n";
	valid=false;
	break;

      }//switch close
    }//if valid close
  } while(!valid);
}
