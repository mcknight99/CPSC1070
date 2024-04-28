#include <iostream>
#include <cmath>

using namespace std;

//ln input > 0
//avoid rounding errors by multiplying by 10,000


int main() {
  cout<<"** Welcome to the CPSC 1071 Payment Calculator **\n\n"; //typing extra endls to match the example is annoying so i just used \n\n
  double principal;
  double monthlyPayment;
  double annualInterestRate;
  //double months; //<-- irrelevant, months is e later

  bool preventInfiniteLoop = false;
  do {
    preventInfiniteLoop=false;
    cout<<"Enter the principal amount: ";
    cin>>principal;
    if(principal<0 || !cin) {
      preventInfiniteLoop=true;
      cout<<"Please put in a valid principal (positive, non zero)"<<endl;
    }
    //principal*=10000; //helps avoid rounding errors when dealing with money
  } while (principal<=0 && preventInfiniteLoop); //if we need to restrict principal such as non-negative

  do{
    cout<<"Enter the annual interest rate (in %): ";
    cin>>annualInterestRate;
    if(annualInterestRate<=0) { //-1200 and lower will cause ln to equal zero 
      cout<<"Please put in a valid annual interest rate (positive, non zero)"<<endl;
    }
  } while(annualInterestRate<=0);
  
  do{
    cout<<"Enter the monthly payment: ";
    cin>>monthlyPayment;
    if(monthlyPayment<=0) {
      cout<<"Please put in a valid monthly payment (positive, non zero)"<<endl;
    }
    //monthlyPayment*=10000; //helps avoid rounding errors when dealing with money
  } while (monthlyPayment<=0);

  
  cout<<"\nCalculating...\n\n";

  double a = log(monthlyPayment);
  //double bp = monthlyPayment-((annualInterestRate/1200)*principal); //irrelevant, testing purposes only
  double b = log(monthlyPayment-((annualInterestRate/1200)*principal));
  double c = log((annualInterestRate/1200)+1);
  double d = a-b;
  double e = d/c; //months
  //cout << "a= "<< a << ", bp= " << bp << ", b= " << b << ", c= " << c << ", d= " << d  << ", e= " << e <<endl;

  //principal = 5000
  //AIR = 15
  //MP = 100
  //months=(log(monthlyPayment)-log(monthlyPayment-(annualInterestRate/1200)*principal)/log((annualInterestRate/1200)+1));

  cout<< round(e) << " months (" << round(10*e/12)/10 << " years) are needed to pay your loan off.\n\n";
  monthlyPayment+=15;

  a = log(monthlyPayment);
  //bp = monthlyPayment-((annualInterestRate/1200)*principal);
  b = log(monthlyPayment-((annualInterestRate/1200)*principal));
  c = log((annualInterestRate/1200)+1);
  d = a-b;  
  e = round(e)-round(d/c); // subtract old months from new months //case 3 wasn't matching for #12 and #13 so i changed it off of e-=d/c it could have been an OOO problem
  
  cout<<"Did you know if you paid an additional $15 per month, you would pay off your loan " << round(e) << " months earlier?\n\n";
  
  return 0;
}

