#ifndef DATE_H
#define DATE_H
#include <string>
class Date{
 public:
  Date(); //defaults to Jan 1 2000
  Date(int month, int day, int year);

  //returns true if it is a leap year
  static bool isLeapYear(int year);
  
  int getMonth();
  int getDay();
  int getYear();

  void setMonth(int month);
  void setDay(int day);
  void setYear(int year);

  Date operator+(int days);
  Date operator-(int days);
  Date& operator++(void);//prefix
  Date operator++(int);//postfix
  Date& operator--(void);//prefix
  Date operator--(int);//postfix
  
  std::string getDayOfWeek(); //implements mystery machine
  std::string toString();

private:
  int month;
  int day;
  int year;
  //int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //shame i couldn't use this because of MysteryMachine. MM could be better if it took the date.getMonth etc of each date instead of reading memory so I don't have to paste this every time I want a month-day limiter
};

#endif