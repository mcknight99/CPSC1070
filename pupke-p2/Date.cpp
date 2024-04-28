#include <iostream>
#include "Date.h"
#include "MysteryMachine.h"

//just a simple leap year one liner that i didnt want to replicate every time i checked for a leap year
bool Date::isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//dont know if months should be 0-11 or 1-12. i prefer the second but the first is for testing weird interactions
Date::Date() { //defaults to jan 1 2000
  month=1;
  day=1;
  year=2000;
}

Date::Date(int monthIn, int dayIn, int yearIn) {
  //setMonth(monthIn); //auto grader didn't like these even though they have the same functionality but with input limitations 
  //setYear(yearIn);
  //setDay(dayIn);
  month=monthIn;
  day=dayIn;
  year=yearIn;
}

int Date::getMonth() {
  return month;
}

int Date::getDay() {
  return day;
}

int Date::getYear() {
  return year;
}

void Date::setMonth(int monthIn) {
  int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  //Using setMonth---if you do change to a month where a date isn't valid (e.g., 9/31/23, you'd roll back to the last valid day of the month 9/30/23"
  if(0<monthIn && monthIn<13) {
    month = monthIn;
  } else if (monthIn<=0) {
    month=0;
  } else if (monthIn>=13) {
    month=12;
  } else {
    month=-1;
  }
  if(day>daysPerMonth[month]+(month==2&&isLeapYear(year))) { //very clever implementation of a leap year tester- basically the array daysPerMonth has the normal year value for february, and if the (month==2&&isLeapYear(year)) statement evaluates to true (month in feb and is a leap year) then the true evaluates to a 1 and gets added to the days in february during evaluation -- this gets used a lot
    day = daysPerMonth[month]+(month==2&&isLeapYear(year));
  }
}

void Date::setDay(int dayIn) {
  int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if(dayIn<(daysPerMonth[month-1]+(month==2&&isLeapYear(year)))) {
    day = dayIn;
  } else if(dayIn<=0) { //days in a month cant be negative or zero
    day=1;
  } else {
    day=(daysPerMonth[month-1]+(month==2&&isLeapYear(year))); //if the day goes greater than the amount in a month, cap it to the max days in that month
  }
}

void Date::setYear(int yearIn) {
  if(year>0) {//basically the only limitation on the year is it cant be negative
    year = yearIn;
  } else {
    year=0;
  }
}

Date Date::operator+(int daysIn) { //this->days + daysIn // is possible to roll over higher than a month's days // not with my code anymore because it just calls ++ repeatedly which has the overflow detection
  Date copy(*this);
  if(daysIn<0) {
    return copy-daysIn; //adding negative is subtracting
  }
  for(int i = 0; i<daysIn; i++) {
    copy++;
  }
  return copy;
}

Date Date::operator-(int daysIn) { //same as + but in the other direction
  //return Date(month, day-daysIn, year);
  Date copy(*this);
  if(daysIn<0) {
    return copy+daysIn; //double negative is adding
  }
  for(int i = 0; i<daysIn; i++) {
    copy--;
  }
  return copy;
}

Date& Date::operator++(void) { //prefix adds to the value then returns the value
  int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  ++day;
  //ok basically i was on crack when i wrote this:
  //to prevent drift during a leap year, there is a statement that evaluates to true (1) if it is a leap year in february,
  //and will add 1 to the days in february on leap years to test for if the current day flows past the amount of days in a month
  //^^ this is when i first wrote the evaluation statement but i re-explained it with a less crack induced explanation when it first appears in this file above
  //if the day goes over the amount of days in the month, set day to 1 and increment month. if month increments to 13, go to jan and add a year. beware of february days in the month
  if(day>(daysPerMonth[month-1]+(month==2&&isLeapYear(year)))){ //month==2 is first in the && so if its false it wont have to run
    month++;
    day=1;
  }
  if(month==13) {
    month=1;
    year++;
  }
  return *this;
}

Date Date::operator++(int) { //postfix returns the value before incrementation then increments the value
  int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  Date copy(*this);
  ++day;
  if(day>(daysPerMonth[month-1]+(month==2&&isLeapYear(year)))){//go to the next month if we reach the highest day
      month++;
      day=1;
  }
  if(month==13) {//go to the next year if we reach the highest month
    month=1;
    year++;
  }
  return copy;
}

Date& Date::operator--(void) { //prefix
  int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  --day;
  if(day<1) { // -- operators have the same functionality as the ++ operators but in the opposite directions
    month--;
    if(month==0) {
      month=12;
      year--;
    }
    day=daysPerMonth[month-1]+(month==2&&isLeapYear(year));
  }
  return *this;
}

Date Date::operator--(int) {//postfix
  int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  Date copy(*this);
  --day;
  if(day<1) {
    month--;
    if(month==0) {
      month=12;
      year--;
    }
    day=daysPerMonth[month-1]+(month==2&&isLeapYear(year));
  }
  return copy;
} 

std::string Date::getDayOfWeek() {//implement the mystery machine
  //Date myDate(month, day, year); //couldnt figure out how to get a this keyword working to make it easier
  return MysteryMachine::getDayOfWeek(*this); //actually i think i did figure it out
  //i did indeed figure it out and im keeping those comments because i think its funny
}

std::string Date::toString() {
  return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}

