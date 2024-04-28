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
double estimateSavings(int currentAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage); //the old function they wanted
void paymentDriver();
int paymentMonths(double principal, double interestRate, double monthlyPayment);
double estimateEarnings(int, int, int, double, double, double); //the new function they want, keeping the old function and calling it from here


int main() {
  runMenuSystem();
}


//starts text based menu to user in terminal
//case does not matter:
//E - estimate how much money an individual will have at retirement
//L - run the payoff calculator that we created in CoLab 1
//Q - quit the program
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
      cout<<"\nThe provided choice was invalid! Please select again.\n\n";
    }
    
    char input = choice.at(0);//first char in the string vector because you can't pass a string through a switch, even if its only one char

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
	cout<<"\nThe provided choice was invalid! Please select again.\n\n";
	valid=false;
	break;

      }//switch close
    }//if valid close
  } while(!valid);
}


//prompt for info to create a rough estimate of how much will be saved by retirement & calls estimateEarnings
//after successfully calculating the estimate, the user is prompted if they want to compute an additional estimate
void estimateDriver() {
  cout<<"Estimate Savings at Retirement\n";
  cout<<"Disclaimer: This is only a rough estimate!\n\n";

  bool valid = false;
  bool redo = false;
  int currentAge1=-1; //initializing as negatives because these should never manage to get through, and if they do then we know where it's going wrong
  int currentAge2=-1;
  int retirementAge=-1;
  double principalSavings=-1;
  double monthlyPayments=-1;
  double annualReturnPercentage=-1;

  //times like this now i really want a function for input validation but ill just copy and paste in the meantime because i know this works. 
  //but the fact that there's a redo message is also a PITA so i had to change around the input validation a bit too
  //i'll just comment how one clone works and the one unique one
  do{ //input validation for first starting age
    if(redo) { //if the do while has repeated because of a misinput
      cout<<"\tRe-enter your age in years: "; //send the redo message
    } else { //but if its the first time going through
      cout<<"\tEnter the first starting age in years: "; //send the first message
    }
    cin>>currentAge1; 
    if(cin.good() && currentAge1>0) {//making sure the cin matches the data type and the variable we are testing for matches its domain
      valid=true;
      redo=false; //reset redo for the next data validation, otherwise they will each start with the redo message. only reset redo to false when the data input is valid
    } else { //when the data isn't valid, reset cin and send an error message
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tAge cannot be 0 or less.\n";
      redo=true; //when the data isnt valid the first time around, this makes sure the next loop will run the redo message instead
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
    if(cin.good() && retirementAge>0 && retirementAge>currentAge1 && retirementAge>currentAge2) {//this is the one unique one because it has two error messages (implied)
      valid=true;
      redo=false;
    } else if(retirementAge<=0) { //if the age input is less than zero
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"\tAge cannot be 0 or less.\n";
      redo=true;
    } else if(retirementAge<=currentAge1 || retirementAge<=currentAge2) { //if the retirement age is less than or equal to the current age. however the 0 case should never happen because it'll be less than the current age anyways. but i wanted to see if i could do multiple data validation types and this worked so i figure why not keep it
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
    cin>>monthlyPayments; 
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

  //curses be upon ye whom changed the required function. i had all the code written out under this comment, but then the requirements changed
  //so what i did was i moved all my code into the new function and changed the old function to estimateSavings and it works like a charm
  estimateEarnings(currentAge1, currentAge2, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage);
  
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


// return the amount estimated at retirement from currentAge
// prints statistics of savings to the user as well
double estimateEarnings(int currentAge, int comparisonAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage) {
  
  cout<<fixed<<setprecision(2);
  //NOTE TO SELF ROUND THE MONEY TO THE SECOND DECIMAL PLACE WHEN OUTPUTTING BUT NOT IN THE DOUBLES, BECAUSE IT NEEDS TO BE MORE PRECISE FOR THE DIFFERENCE LATER
  //this note to self came in handy because thats why the roughsavings vs savings variables exist. the roughsavings are unrounded so they get subtracted then rounded for the potential missed out money (the difference is 1 penny in 50% of cases because of the order of rounding decimals. the potential difference has to be rounded after subtraction to match by one penny.
  cout<<".\n.\n...calculating\n";

  //first age statistics
  cout<<"For starting to save at retirement at age " <<currentAge<<":\n\n";
  double roughsavings1 = estimateSavings(currentAge, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage/12); //divide by 12 for a monthly earning? i have no idea // well that worked and i dont even know if thats the intended way but now i guess its monthlyReturnPercentage
  double savings1 = static_cast<double>(round(roughsavings1)/100); 
  double growth1 = (savings1-principalSavings)-(monthlyPayments*((retirementAge-currentAge)*12)); //and whatever happens to the for loop in estimateEarnings has to happen here too because its the amount of months
  cout<<"Estimated Retirement Savings: $" << savings1<<endl;
  cout<<"Estimated Retirement Growth: $"<<growth1<<endl;

  //second age statistics
  cout<<"\nFor starting to save at retirement at age " <<comparisonAge<<":\n\n";
  double roughsavings2 = estimateSavings(comparisonAge, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage/12);
  double savings2 = static_cast<double>(round(roughsavings2)/100);
  double growth2 = (savings2-principalSavings)-(monthlyPayments*((retirementAge-comparisonAge)*12)); //and whatever happens to the for loop in estimateEarnings has to happen here too because its the amount of months
  cout<<"Estimated Retirement Savings: $" << savings2<<endl;
  cout<<"Estimated Retirement Growth: $"<<growth2<<endl;

  cout<<"\n\n\nFor a difference in waiting "<< abs(comparisonAge-currentAge) <<" years before starting to invest in\nretirement, you can miss out potentially on $"<<round(abs(roughsavings2-roughsavings1))/100<<endl;
  return savings1;

}


// return amount estimated at retirement
//this used to be the old function we had as estimateEarnings, but I had to move some things around. the statistics in the new estimateEarnings would have gone in here too but the requirements are the estimateEarnings function has the statistics print. This code is what can be prevented from being duplicated in the new estimateEarnings
double estimateSavings(int currentAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage) {
  double savings = principalSavings;
  for(int i = 0; i<(retirementAge-currentAge)*12; i++) { //repeat a monthly calculation every month from current age to retirement age. if some numbers are off, the subtraction might be giving some errors. try adding or subtracting 12 to the months //thankfully there was no error, but I was thinking this just in case you wanted to retire at the age rather than the end of the year of that age (similar to how years vs birthdays don't line up, so this was a safe but thankfully unneeded reminder)
    savings = (savings*(1+(annualReturnPercentage/100)))+monthlyPayments;
    //cout<<i<<" months savings is now "<<savings<<", ";
  }
  //cout<<fixed<<"savings pre round: "<<savings*100<<endl;
  return savings*100; //mult x 10000 for money precision
}


//prompt for information to determine the loan repayment & call paymentMonths()
//after calculating estimate, user is prompted if they want to compute an additional estimate
void paymentDriver() {
  cout<<"Loan Payment Calculator\n\n";

  bool valid = false;
  double principal=-1; //making these -1 because they shouldn't pass to the function and if they do we know something happened
  double monthlyPayment=-1;
  double annualInterestRate=-1;

  //i would like to make a function in the future to do input validation that is just checking if it matches the variable type and let whatever calls the function do the domain testing (like num>0) but i dont care to do that while i know how to do what works //ALSO the fact that they need different error messages, but that could be solved with a string parameter for the input validation function for a dynamic error message
  //i also wrote the comment above this before i wrote the validation for the other driver and boy oh boy im glad i didnt spend the time writing a function because those were some funky different ones that required a unique validation from these, but i could probably write a function that incorporated all of the features up to now with overloading functions 
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
    cout<<"Enter the annual interest rate (in percent): ";
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
  do{ //monthly payment input validation
    cout<<"Enter the monthly payment: $";
    cin>>monthlyPayment;
    if(cin.good()&&monthlyPayment>0) {
      valid=true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Please put in a valid monthly payment (positive, non zero)";
    }
  } while(!valid); //end of monthly payment input validation

  cout<<"\nCalculating...\n\n";
  double months = static_cast<double>(paymentMonths(principal, annualInterestRate, monthlyPayment)); //the rounding bug was during division it kept it as an int even though the division was by doubles in the original function. casting the int to a double should hopefully fix this problem
  
  /*
  cout<<"raw months = " <<months<<endl;
  cout<<"pre round months = " << months/(12*100)<<endl;
  cout<<"post round months = "<<(round(months/(12*100))/10)<<endl;
  */ //these testing couts helped show the difference between the year calculation here and in the function

  cout<<fixed<<setprecision(0);//because the savings function turns it to fixed to 2
  cout<<floor(months/1)<<" months ("<<setprecision(1)<<months/12<<" years) are needed to pay your loan off.\n\n";

  int monthsP15 = paymentMonths(principal, annualInterestRate, monthlyPayment+15);

  int difference = round((months-monthsP15)/1);
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
  //months = round(months*1000); //giving it 3 decimal places of precision because im 1 decimal off on the checker and in the old code it was right but its wrong here and i think it has to do with when it rounds
  /*
  cout<<"raw months = " <<months<<endl;
  cout<<"pre round months = " << months/(12*100)<<endl;
  cout<<"post round months = "<<(round(months/(12*100))/10)<<endl;  
  */ //these testing couts helped show the difference between the year calculation here and where it's called
  return round(months);//i dont know if it wants rounded months or floored months or ceiled months 
}




