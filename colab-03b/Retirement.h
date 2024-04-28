#ifndef RETIRE_H
#define RETIRE_H

class Retirement{
 public:
  static void estimateDriver();

 private:
  static double estimateEarnings(int, int, double, double, double);//"new" functionality that i thankfully never touched
  static double estimateSavings(int, int, int, double, double, double); //old functionality
};
#endif
