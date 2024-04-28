#include <iostream> //input and output to terminal
#include <limits> //input validation
#include <cmath> //rounding
#include <iomanip> //setprecision
#include "Loan.h"



//prompt for information to determine the loan repayment & call paymentMonths()
//after calculating estimate, user is prompted if they want to compute an additional estimate
void Loan::paymentDriver() {
  std::cout<<"Loan Payment Calculator\n\n";

  bool valid = false;
  double principal=-1; //making these -1 because they shouldn't pass to the function and if they do we know something happened
  double monthlyPayment=-1;
  double annualInterestRate=-1;

  //i would like to make a function in the future to do input validation that is just checking if it matches the variable type and let whatever calls the function do the domain testing (like num>0) but i dont care to do that while i know how to do what works //ALSO the fact that they need different error messages, but that could be solved with a string parameter for the input validation function for a dynamic error message
  //i also wrote the comment above this before i wrote the validation for the other driver and boy oh boy im glad i didnt spend the time writing a function because those were some funky different ones that required a unique validation from these, but i could probably write a function that incorporated all of the features up to now with overloading functions 
  do{ //principal input validation
    std::cout<<"Enter the principal amount: $";
    std::cin>>principal;
    if(std::cin.good() && principal>0) {
      valid=true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"Please put in a valid principal (positive, non zero)";
    }
  } while(!valid); //end of principal input validation

  valid=false; //reset valid
  do{ //annual interest rate input validation
    std::cout<<"Enter the annual interest rate (in percent): ";
    std::cin>>annualInterestRate;
    if(std::cin.good() && annualInterestRate>=0) {
      valid=true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"Please put in a valid annual interest rate (positive)";
    }
  } while(!valid); //end of annual interest rate input validation

  valid=false;
  do{ //monthly payment input validation
    std::cout<<"Enter the monthly payment: $";
    std::cin>>monthlyPayment;
    if(std::cin.good()&&monthlyPayment>0) {
      valid=true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"Please put in a valid monthly payment (positive, non zero)";
    }
  } while(!valid); //end of monthly payment input validation

  std::cout<<"\nCalculating...\n\n";
  double months = static_cast<double>(paymentMonths(principal, annualInterestRate, monthlyPayment)); //the rounding bug was during division it kept it as an int even though the division was by doubles in the original function. casting the int to a double should hopefully fix this problem
  
  /*
  cout<<"raw months = " <<months<<endl;
  cout<<"pre round months = " << months/(12*100)<<endl;
  cout<<"post round months = "<<(round(months/(12*100))/10)<<endl;
  */ //these testing couts helped show the difference between the year calculation here and in the function

  std::cout<<std::fixed<<std::setprecision(0);//because the savings function turns it to fixed to 2
  std::cout<<floor(months/1)<<" months ("<<std::setprecision(1)<<months/12<<" years) are needed to pay your loan off.\n\n";

  int monthsP15 = paymentMonths(principal, annualInterestRate, monthlyPayment+15);

  int difference = round((months-monthsP15)/1);
  std::cout<<"Did you know if you paid an additional $15 per month, you would pay off your loan "<<difference<<" months earlier?\n\n";

  valid=false;
  do{
    std::cout<<"Calculate another loan payoff? (y/n): ";
    std::string choice = "n";
    std::cin>>choice;
    char switchchoice = choice.at(0);
    switch (switchchoice) {
    case 'y': case 'Y':
      paymentDriver();
      valid=true;
      break;
    case 'n': case 'N':
      std::cout<<std::endl;
      valid=true;
      break;
    default:
      std::cout<<"Invalid Input! Please choose again.\n";
      break;
    }
  } while(!valid);
}


//print statistics & return months to pay back
int Loan::paymentMonths(double principal, double interestRate, double monthlyPayment) {
  double numerator1 = log(monthlyPayment);
  double numerator2 = log(monthlyPayment-((interestRate/1200)*principal));
  double denominator = log((interestRate/1200)+1);
  double numerator = numerator1-numerator2;
  double months = numerator/denominator;
  //months = round(months*1000); //giving it 3 decimal places of precision because im 1 decimal off on the checker and in the old code it was right but its wrong here and i think it has to do with when it rounds
  /*
  cout<<"raw months = " <<months<<endl;
  cout<<"pre round months = " << months/(12*100)<<endl;
  cout<<"post round months = "<<(round(months/(12*100))/10)<<endl;  
  */ //these testing couts helped show the difference between the year calculation here and where it's called
  return round(months);//i dont know if it wants rounded months or floored months or ceiled months 
}

