#include "Retirement.h"
#include <iostream>//input and output to terminal
#include <limits>//input validation limiting
#include <cmath>//rounding
#include <iomanip> //setprecision



//prompt for info to create a rough estimate of how much will be saved by retirement & calls estimateEarnings
//after successfully calculating the estimate, the user is prompted if they want to compute an additional estimate
void Retirement::estimateDriver() {
  std::cout<<"Estimate Savings at Retirement\n";
  std::cout<<"Disclaimer: This is only a rough estimate!\n\n";

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
      std::cout<<"\tRe-enter your age in years: "; //send the redo message
    } else { //but if its the first time going through
      std::cout<<"\tEnter your current age in years: "; //send the first message
    }
    std::cin>>currentAge1; 
    if(std::cin.good() && currentAge1>0) {//making sure the cin matches the data type and the variable we are testing for matches its domain
      valid=true;
      redo=false; //reset redo for the next data validation, otherwise they will each start with the redo message. only reset redo to false when the data input is valid
    } else { //when the data isn't valid, reset cin and send an error message
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tAge cannot be 0 or less.\n";
      redo=true; //when the data isnt valid the first time around, this makes sure the next loop will run the redo message instead
    }
  } while(!valid); //end of input validation for first starting age
  valid=false;
  /*
  do{ //input validation for second starting age
    if(redo) {
      std::cout<<"\tRe-enter your age in years: ";
    } else {
      std::cout<<"\tEnter the second starting age in years: ";
    }
    std::cin>>currentAge2;
    if(std::cin.good() && currentAge2>0) {
      valid=true;
      redo=false;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tAge cannot be 0 or less.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for second starting age
  valid=false;
  */
  currentAge2=currentAge1;
do{ //input validation for target retirement age
    if(redo) {
      std::cout<<"\tRe-enter your target age in years: ";
    } else {
      std::cout<<"\tEnter your target retirement age: ";
    }
    std::cin>>retirementAge;
    if(std::cin.good() && retirementAge>0 && retirementAge>currentAge1 && retirementAge>currentAge2) {//this is the one unique one because it has two error messages (implied)
      valid=true;
      redo=false;
    } else if(retirementAge<=0) { //if the age input is less than zero
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tAge cannot be 0 or less.\n";
      redo=true;
    } else if(retirementAge<=currentAge1 || retirementAge<=currentAge2) { //if the retirement age is less than or equal to the current age. however the 0 case should never happen because it'll be less than the current age anyways. but i wanted to see if i could do multiple data validation types and this worked so i figure why not keep it
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tYour target age cannot be less than or equal your current age.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for retirement age
  valid=false;
  do{ //input validation for principal savings
    if(redo) {
      std::cout<<"\tRe-enter your savings: $";
    } else {
      std::cout<<"\tHow much have you saved towards retirement?: $";
    }
    std::cin>>principalSavings;
    if(std::cin.good() && principalSavings>0) {
      valid=true;
      redo=false;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tYour savings cannot be negative.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for principal savings
  valid=false;
  do{ //input validation for monthly payment
    if(redo) {
      std::cout<<"\tRe-enter your monthly contribution: $";
    } else {
      std::cout<<"\tEnter your monthly contribution to retirement: $";
    }
    std::cin>>monthlyPayments; 
    if(std::cin.good() && monthlyPayments>0) {
      valid=true;
      redo=false;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tYour monthly contribution cannot be less than or equal to zero.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for monthly payment
  valid=false;
  do{ //input validation for annual return percentage
    if(redo) {
      std::cout<<"\tRe-enter your rate (in percent): ";
    } else {
      std::cout<<"\tEnter the estimated annual return on investment (in percent): ";
    }
    std::cin>>annualReturnPercentage;
    if(std::cin.good() && annualReturnPercentage>0) {
      valid=true;
      redo=false;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\tYour rate cannot be less than zero.\n";
      redo=true;
    }
  } while(!valid); //end of input validation for annual return percentage

  //curses be upon ye whom changed the required function. i had all the code written out under this comment, but then the requirements changed
  //so what i did was i moved all my code into the new function and changed the old function to estimateSavings and it works like a charm
  estimateSavings(currentAge1, currentAge2, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage);
  char choice = 'i';
  valid = false;
  do{
    std::cout<<"Calculate another estimate? (y/n): ";
    std::string in = "i";
    std::cin>>in;
    choice = in.at(0); //edge case of a string being put in with y or n starting it but i dont really care enough 
    //std::cout<<choice<<" is choice";
    switch (choice) {
    case 'y': case 'Y':
      std::cout<<std::endl;
      estimateDriver();
      valid=true;
      break;
    case 'n' : case 'N':
      std::cout<<std::endl;
      valid=true;
      break;
    default:
      std::cout<<"Invalid Input! Please choose again.\n";
      break;
    }
  } while(!valid);
  //std::cout<<std::endl;
}


// return the amount estimated at retirement from currentAge
// prints statistics of savings to the user as well
double Retirement::estimateSavings(int currentAge, int comparisonAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage) {
  
  std::cout<<std::fixed<<std::setprecision(2);
  //NOTE TO SELF ROUND THE MONEY TO THE SECOND DECIMAL PLACE WHEN OUTPUTTING BUT NOT IN THE DOUBLES, BECAUSE IT NEEDS TO BE MORE PRECISE FOR THE DIFFERENCE LATER
  //this note to self came in handy because thats why the roughsavings vs savings variables exist. the roughsavings are unrounded so they get subtracted then rounded for the potential missed out money (the difference is 1 penny in 50% of cases because of the order of rounding decimals. the potential difference has to be rounded after subtraction to match by one penny.
  std::cout<<".\n.\n...calculating\n\n";

  //first age statistics
  //std::cout<<"For starting to save at retirement at age " <<currentAge<<":\n\n";
  double roughsavings1 = estimateEarnings(currentAge, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage/12); //divide by 12 for a monthly earning? i have no idea // well that worked and i dont even know if thats the intended way but now i guess its monthlyReturnPercentage
  double savings1 = static_cast<double>(round(roughsavings1)/100); 
  double growth1 = (savings1-principalSavings)-(monthlyPayments*((retirementAge-currentAge)*12)); //and whatever happens to the for loop in estimateEarnings has to happen here too because its the amount of months
  std::cout<<"Estimated Retirement Savings: $" << savings1<<std::endl;
  std::cout<<"Estimated Retirement Growth: $"<<growth1<<std::endl<<std::endl;

  //second age statistics
  //std::cout<<"\nFor starting to save at retirement at age " <<comparisonAge<<":\n\n";
  double roughsavings2 = estimateEarnings(comparisonAge, retirementAge, principalSavings, monthlyPayments, annualReturnPercentage/12);
  double savings2 = static_cast<double>(round(roughsavings2)/100);
  double growth2 = (savings2-principalSavings)-(monthlyPayments*((retirementAge-comparisonAge)*12)); //and whatever happens to the for loop in estimateEarnings has to happen here too because its the amount of months
  //std::cout<<"Estimated Retirement Savings: $" << savings2<<std::endl;
  //std::cout<<"Estimated Retirement Growth: $"<<growth2<<std::endl;

  //std::cout<<"\n\n\nFor a difference in waiting "<< abs(comparisonAge-currentAge) <<" years before starting to invest in\nretirement, you can miss out potentially on $"<<round(abs(roughsavings2-roughsavings1))/100<<std::endl;
  return savings1;

}

// return amount estimated at retirement
//this used to be the old function we had as estimateEarnings, but I had to move some things around. the statistics in the new estimateEarnings would have gone in here too but the requirements are the estimateEarnings function has the statistics print. This code is what can be prevented from being duplicated in the new estimateEarnings
double Retirement::estimateEarnings(int currentAge, int retirementAge, double principalSavings, double monthlyPayments, double annualReturnPercentage) {
  double savings = principalSavings;
  for(int i = 0; i<(retirementAge-currentAge)*12; i++) { //repeat a monthly calculation every month from current age to retirement age. if some numbers are off, the subtraction might be giving some errors. try adding or subtracting 12 to the months //thankfully there was no error, but I was thinking this just in case you wanted to retire at the age rather than the end of the year of that age (similar to how years vs birthdays don't line up, so this was a safe but thankfully unneeded reminder)
    savings = (savings*(1+(annualReturnPercentage/100)))+monthlyPayments;
    //cout<<i<<" months savings is now "<<savings<<", ";
  }
  //cout<<fixed<<"savings pre round: "<<savings*100<<endl;
  return savings*100; //mult x 10000 for money precision
}

