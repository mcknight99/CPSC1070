#include <iostream>
#include <iomanip> //we're dealing with money, this is useful for output

#include "SalesPerson.h"

using namespace std;

//defined public functions
SalesPerson::SalesPerson() { //format for a constructor; what its called:reference call
  for (int i = 0; i< MONTHS; i++) {
    sales[i] = 0.0;
  }
}

//accessors
void SalesPerson::getSalesFromUser() {
  double salesFigure = 0.0;

  for(int i = JANUARY; i<=DECEMBER; i++) {
    cout<<"Enter sales figure for ";
    printMonth(staticCast<Months>(i));
    cout<<": $";
    cin>>salesFigure; //not supposed to keep/allow negative numbers

    //will need to call setSales(i, salesFigure);
    setSales(i, salesFigure);
  }

}


void SalesPerson::printAnnualSales() {
  cout<<setprecision(2)<<fixed<<"Total annual sales are $"<<totalAnnualSales()<<endl;
  
}


void SalesPerson::printMonth(Months inMonth) {
  switch(inMonth) {
  case JANUARY: cout<<"January";
  case FEBRUARY: cout<<"February";
  case MARCH: cout<<"March";
  case APRIL: cout<<"April";
  case MAY: cout<<"May";
  case JUNE: cout<<"June";
  case JULY: cout<<"July";
  case AUGUST: cout<<"August";
  case SEPTEMBER: cout<<"September";
  case OCTOBER: cout<<"October";
  case NOVEMBER: cout<<"November";
  case DECEMBER: cout<<"December";
    
  }
}


//private functions
void salesPerson::setSales(int month, double amount) {
  //how can we validate if amount is only positive

  if(month>=1 && month<=MONTHS) {
    sales[month-1] = amount;
  } else {
    cout<<"Error message: input months or sales figure are not valid";//not a great place to put an error/reprompt place, should place it in getSalesFromUser to reprompt for the same month
  }
  
  sales[month-1] = amount;//off by 1 because input is 1-12 month, but is stored as 0-11
  


}



void SalesPerson::totalAnnualSales() {
  double total = 0.0;
  for(int i = 1; i< MONTHS; i++) {
    total += sales[i];
  }
  return total; //summing up months sales
}
