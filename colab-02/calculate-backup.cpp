//Samuel Pupke
//CPSC 1071: Section 5
//Team 3, A++
//Date: Oct 2, 2023


#include <iostream> //need to input and output to terminal
#include <limits> //need for input validation limiting
#include <cmath> //rounding
#include <iomanip> //setprecision

using namespace std;

//prototypes
void runMenuSystem();
void estimateDriver();
double estimateEarnings(int currentAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage);
void paymentDriver();
int paymentMonths(double principal, double interestRate, double monthlyPayment);



int main() {
  runMenuSystem();



}


//starts text based menu
void runMenuSystem() {
 
  string choice = "  ";
  bool valid = false;
  do{
    cout<<"******* Welcome to Clementine Financial *******\n\n";
    cout<<"Menu:\n";
    cout<<"\t[E] Estimate how much money at retirement\n";
    cout<<"\t[L] Loan payoff calculator\n";
    cout<<"\t[Q] Quit program\n\n";
    cout<<" Enter your choice and press enter: ";
    cin>>choice;
    if(cin.good() && choice.length()==1) {
      valid=true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"The provided choice was invalid! Please select again.\n\n";
    }
    char input = choice.at(0);//first char in the string vector
    if(valid) {//prevents running the switch case, thus causing a default double print of invalid choice
      switch (input) {//switch open
      case 'E' : case 'e':
	//CODE FOR ESTIMATE OF MONEY AT RETIREMENT
	estimateDriver();
	valid=false;
	break;
      case 'L': case 'l':
	//CODE FOR LOAN PAYOFF CALCULATOR
	paymentDriver();
	valid=false;
	break;
      case 'Q': case 'q':
	//CODE FOR QUIT PROGRAM
	valid=true;
	break;
      default:
	cout<<"The provided choice was invalid! Please select again.\n\n";
	valid=false;
	break;

      }//switch close
    }//if valid close
  } while(!valid);
}


//prompt for info to create a rough estimate of how much will be saved by retirement & calls estimateEarnings
void estimateDriver() {
  cout<<"Estimate Savings at Retirement\n";
  cout<<"Disclaimer: This is only a rough estimate!\n\n";

  bool valid = false;
  bool redo = false;
  int currentAge1=-1;
  int currentAge2=-1;
  int retirementAge=-1;
  double principalSavings=-1;
  double monthlyPayments=-1;
  double annualReturnPercentage=-1;

  //times like this now i really want a function for input validation but ill just copy and paste in the meantime because i know this works. 
  //but the fact that there's a redo message is also a PITA so i had to change around the input validation a bit too
  do{ //input validation for first starting age
    if(redo) {
      cout<<"\tRe-enter your age in years: ";
    } else {
      cout<<"\tEnter the first starting age in years: ";
    }
    cin>>currentAge1;
    if(cin.good() && currentAge1>0) {
      valid=true;
      redo=false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tAge cannot be 0 or less.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for first starting age
  valid=false;
  do{ //input validation for second starting age
    if(redo) {
      cout<<"\tRe-enter your age in years: ";
    } else {
      cout<<"\tEnter the second starting age in years: ";
    }
    cin>>currentAge2;
    if(cin.good() && currentAge2>0) {
      valid=true;
      redo=false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tAge cannot be 0 or less.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for second starting age
  valid=false;
  do{ //input validation for target retirement age
    if(redo) {
      cout<<"\tRe-enter your target age in years: ";
    } else {
      cout<<"\tEnter your target retirement age: ";
    }
    cin>>retirementAge;
    if(cin.good() && retirementAge>0 && retirementAge>currentAge1 && retirementAge>currentAge2) {
      valid=true;
      redo=false;
    } else if(retirementAge<=0) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tAge cannot be 0 or less.\n";
      redo=true;
    } else if(retirementAge<=currentAge1 || retirementAge<=currentAge2) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tYour target age cannot be less than or equal your current age.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for retirement age
  valid=false;
  do{ //input validation for principal savings
    if(redo) {
      cout<<"\tRe-enter your savings: $";
    } else {
      cout<<"\tHow much have you saved already towards retirement?: $";
    }
    cin>>principalSavings;
    if(cin.good() && principalSavings>0) {
      valid=true;
      redo=false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tYour savings cannot be negative.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for principal savings
  valid=false;
  do{ //input validation for monthly payment
    if(redo) {
      cout<<"\tRe-enter your monthly contribution: $";
    } else {
      cout<<"\tEnter your monthly contribution to retirement: $";
    }
    cin>>monthlyPayments; //////////////////////////////////////////////////////
    if(cin.good() && monthlyPayments>0) {
      valid=true;
      redo=false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tYour monthly contribution cannot be less than or equal to zero.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for monthly payment
  valid=false;
  do{ //input validation for annual return percentage
    if(redo) {
      cout<<"\tRe-enter your rate (in percent): ";
    } else {
      cout<<"\tEnter the estimated annual return on investment (in percent): ";
    }
    cin>>annualReturnPercentage;
    if(cin.good() && annualReturnPercentage>0) {
      valid=true;
      redo=false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tYour rate cannot be less than zero.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for annual return percentage

  cout<<fixed<<setprecision(2);
  //NOTE TO SELF ROUND THE MONEY TO THE SECOND DECIMAL PLACE WHEN OUTPUTTING BUT NOT IN THE DOUBLES, BECAUSE IT NEEDS TO BE MORE PRECISE FOR THE DIFFERENCE LATER
  cout<<".\n.\n...calculating\n";
  cout<<"For starting to save at retirement at age " <<currentAge1<<":\n\n";
  double roughsavings1 = estimateEarnings(currentAge1, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage/12);
  double savings1 = static_cast<double>(round(roughsavings1)/100); //divide by 12 for a monthly earning? i have no idea // well that worked and i dont even know if thats the intended way but now i guess its monthlyReturnPercentage
  
  double growth1 = (savings1-principalSavings)-(monthlyPayments*((retirementAge-currentAge1)*12)); //and whatever happens to the for loop in estimateEarnings has to happen here too because its the amount of months
  cout<<"Estimated Retirement Savings: $" << savings1<<endl;
  cout<<"Estimated Retirement Growth: $"<<growth1<<endl;
  cout<<"\nFor starting to save at retirement at age " <<currentAge2<<":\n\n";
  double roughsavings2 = estimateEarnings(currentAge2, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage/12);
  double savings2 = static_cast<double>(round(roughsavings2)/100);
  double growth2 = (savings2-principalSavings)-(monthlyPayments*((retirementAge-currentAge2)*12)); //and whatever happens to the for loop in estimateEarnings has to happen here too because its the amount of months
  cout<<"Estimated Retirement Savings: $" << savings2<<endl;
  cout<<"Estimated Retirement Growth: $"<<growth2<<endl;

  cout<<"\n\n\nFor a difference in waiting "<< abs(currentAge2-currentAge1) <<" years before starting to invest in\nretirement, you can miss out potentially on $"<<round(abs(roughsavings2-roughsavings1))/100<<endl;


  cout<<"Calculate another estimate? (y/n): ";
  string choice = "n";
  cin>>choice;
  char switchchoice = choice.at(0);
  switch (switchchoice) {
  case 'y': case 'Y':
    estimateDriver();
    break;
  default:
    break;
  }
  cout<<endl;
}


// print out statistics & return amount estimated at retirement
double estimateEarnings(int currentAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage) {
  double savings = principalSavings;
  for(int i = 0; i<(retirementAge-currentAge)*12; i++) { //repeat a monthly calculation every month from current age to retirement age. if some numbers are off, the subtraction might be giving some errors. try adding or subtracting 12 to the months
    savings = (savings*(1+(annualReturnPercentage/100)))+monthlyPayments;
    //cout<<i<<" months savings is now "<<savings<<", ";
  }
  //cout<<fixed<<"savings pre round: "<<savings*100<<endl;
  return savings*100; //mult x 10000 for money precision
}


//prompt for information to determine the loan repayment & call paymentMonths()
//after calculating estimate, user is prompted if they want to compute an additional estimate
void paymentDriver() {


  bool valid = false;
  double principal=-1; //making these -1 because they shouldn't pass to the function and if they do we know something happened
  double monthlyPayment=-1;
  double annualInterestRate=-1;

  //i would like to make a function in the future to do input validation that is just checking if it matches the variable type and let whatever calls the function do the domain testing (like num>0) but i dont care to do that while i know how to do what works //ALSO the fact that they need different error messages, but that could be solved with a string parameter for the input validation function for a dynamic error message
  do{ //principal input validation
    cout<<"Enter the principal amount: $";
    cin>>principal;
    if(cin.good() && principal>0) {
      valid=true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Please put in a valid principal (positive, non zero)";
    }
  } while(!valid); //end of principal input validation

  valid=false; //reset valid
  do{ //annual interest rate input validation
    cout<<"Enter the annual interest rate (in %): ";
    cin>>annualInterestRate;
    if(cin.good() && annualInterestRate>=0) {
      valid=true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Please put in a valid annual interest rate (positive)";
    }
  } while(!valid); //end of annual interest rate input validation

  valid=false;
  do{
    cout<<"Enter the monthly payment: $";
    cin>>monthlyPayment;
    if(cin.good()&&monthlyPayment>0) {
      valid=true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Please put in a valid monthly payment (positive, non zero)";
    }
  } while(!valid);

  cout<<"\nCalculating...\n\n";
  double months = static_cast<double>(paymentMonths(principal, annualInterestRate, monthlyPayment)); //the rounding bug was during division it kept it as an int even though the division was by doubles in the original function. casting the int to a double should hopefully fix this problem
  
  /*
  cout<<"raw months = " <<months<<endl;
  cout<<"pre round months = " << months/(12*100)<<endl;
  cout<<"post round months = "<<(round(months/(12*100))/10)<<endl;
  */ //these testing couts helped show the difference between the year calculation here and in the function


  cout<<floor(months/1000)<<" months ("<<(round(months/(12*100))/10)<<" years) are needed to pay your loan off.\n\n";

  int monthsP15 = paymentMonths(principal, annualInterestRate, monthlyPayment+15);

  int difference = round((months-monthsP15)/1000);
  cout<<"Did you know if you paid an additional $15 per month, you would pay off your loan "<<difference<<" months earlier?\n\n";

  
  cout<<"Calculate another loan payoff? (y/n): ";
  string choice = "n";
  cin>>choice;
  char switchchoice = choice.at(0);
  switch (switchchoice) {
  case 'y': case 'Y':
    paymentDriver();
    break;
  default:
    break;
  }
  cout<<endl;
}


//print statistics & return months to pay back
int paymentMonths(double principal, double interestRate, double monthlyPayment) {
  double numerator1 = log(monthlyPayment);
  double numerator2 = log(monthlyPayment-((interestRate/1200)*principal));
  double denominator = log((interestRate/1200)+1);
  double numerator = numerator1-numerator2;
  double months = numerator/denominator;
  months = round(months*1000); //giving it 3 decimal places of precision because im 1 decimal off on the checker and in the old code it was right but its wrong here and i think it has to do with when it rounds
  /*
  cout<<"raw months = " <<months<<endl;
  cout<<"pre round months = " << months/(12*100)<<endl;
  cout<<"post round months = "<<(round(months/(12*100))/10)<<endl;  
  */ //these testing couts helped show the difference between the year calculation here and where it's called
  return months; 
}



