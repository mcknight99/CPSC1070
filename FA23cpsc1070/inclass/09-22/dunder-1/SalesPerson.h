#ifndef SALESPERSON
#define SALESPERSON

  static const int MONTHS = 12;

class SalesPerson {
 public:
  SalesPerson(); //default constructor
  void getSalesFromUser(); //function to get sales numbers
  void printAnnualSales(); //summarize and print sales
  
 private:
  
  //don't want sales values to be public
  double sales[MONTHS];//12 mo/yr
  double totalAnnualSales(); //utility function
  void setSales(int, double); //set sales for a month

  
};

#endif
