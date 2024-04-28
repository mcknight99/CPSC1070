#ifndef LOAN_H
#define LOAN_H

class Loan{
 public:
  static void paymentDriver();

 private:
  static int paymentMonths(double, double, double);
};
#endif
