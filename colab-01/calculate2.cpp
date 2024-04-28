#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//ln input > 0
//avoid rounding errors by multiplying by 10,000


int main() {
  cout<<"** Welcome to the CPSC 1071 Payment Calculator **\n\n"; //typing extra endls to match the example is annoying so i just used \n\n
  double principal;
  double monthlyPayment;
  double annualInterestRate;
  //double months; //unused, e is months later
  
  do {
    cout<<"Enter the principal amount: ";
    cin>>principal;
    bool test = false; //replace false with the test case, such as (principal<0)
    if(test) {
      cout<<"Please put in a valid principal"<<endl;
    }
    //principal*=10000; //helps avoid rounding errors when dealing with money
  } while (false); //if we need to restrict principal such as non-negative

  do{
    cout<<"Enter the annual interest rate (in %): ";
    cin>>annualInterestRate;
    if(annualInterestRate<-1200) { //-1200 and lower will cause ln to equal zero 
      cout<<"Please put in a valid annual interest rate (>-1200)"<<endl;
    }
  } while(annualInterestRate<-1200);
  
  do{
    cout<<"Enter the monthly payment: ";
    cin>>monthlyPayment;
    if(monthlyPayment<0) {
      cout<<"Please put in a valid monthly payment (positive, non zero)"<<endl;
    }
    //monthlyPayment*=10000; //helps avoid rounding errors when dealing with money
  } while (monthlyPayment<0);

  
  cout<<"\nCalculating...\n\n";

  double a = log(monthlyPayment);
  //double bp = monthlyPayment-((annualInterestRate/1200)*principal); //testing variable only
  double b = log(monthlyPayment-((annualInterestRate/1200)*principal));
  double c = log((annualInterestRate/1200)+1);
  double d = a-b;
  double e = d/c; //months
  //e+=0.001;
  //cout << setprecision(100000) << "a= "<< a << ", bp= " << bp << ", b= " << b << ", c= " << c << ", d= " << d  << ", e= " << e <<endl;
  //cout<<"real months: " <<e<<endl;
  //principal = 5000
  //AIR = 15
  //MP = 100
  //months=(log(monthlyPayment)-log(monthlyPayment-(annualInterestRate/1200)*principal)/log((annualInterestRate/1200)+1));

  cout<< round(e) << " months (" << round(10*e/12)/10 << " years) are needed to pay your loan off.\n\n";
  monthlyPayment+=10;//this stupid mf i forgot about and was messing up all my extra credit calculations

  a = log(monthlyPayment);
  //bp = monthlyPayment-((annualInterestRate/1200)*principal);
  b = log(monthlyPayment-((annualInterestRate/1200)*principal));
  c = log((annualInterestRate/1200)+1);
  d = a-b;  
  double e2 = e-(d/c); // subtract old months from new months

  cout<<"Did you know if you paid an additional $10 per month, you would pay off your loan " << round(e2) << " months earlier?\n\n";
  monthlyPayment-=10; //to bring it back down afterwards to reset from the "did you know"
  //cout<<"months: " <<e << ", monthlyPayment: " << monthlyPayment<<endl;
  e = round(e*1000)/1000;
  double total = e*monthlyPayment; //12 payments with 1 payment per month per year just means months for payments
  //cout<<"total: " << total <<endl;
  if((int)round(total*100)%10!=0) {
    cout<<"The total interest paid is $" << (round((total-principal)*100))/100 << " and the total amount you'll pay is $" << (round(total*100))/100<<".\n\n";
  } else {
    cout<<"The total interest paid is $" << (round((total-principal)*100))/100 << "0 and the total amount you'll pay is $" << (round(total*100))/100<<"0.\n\n";
  }

  return 0;
}

