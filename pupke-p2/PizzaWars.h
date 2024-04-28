#ifndef PIZZAWARS_H
#define PIZZAWARS_H 
#include <string> //strings
#include "Date.h"
#include "PizzaStore.h"
#include <iostream> //terminal io
#include <fstream> //for file output
#include <unistd.h> //required for usleep(x) method to tick every 0.05secy
#include <cstdlib> //randomizer
#include <ctime> //seeding randomizer
#include <chrono> //the clock runs too fast, the randomizer gets the same values in the same second. seeding with ms could fix (C++.c)
#include <iomanip> //output file formatting

class PizzaWars{
 public:
  PizzaWars();

  //driver function for the entire PizzaWars simulation
  static void runSimulation();

  protected:  //UNCOMMENT IN THE FUTURE, JUST MAKING IT PUBLIC FOR TESTING
  //dynamically allocates & fills a date array with 7 days starting with the date passed in the parameter
  //return should point to the first date in the 7 day array
  static Date * allocateWeekOfDates(Date date);

  // given an array of dates, will iterate through each day and call
  // runDaySimulation with it. writes the results from runDaySimulation
  //to the log.txt using writeToFile
  static void runSeriesSimulation(Date *dates, int length);

  //Determines whiich of the two pizza stores win
  //Returns the name of the store which won
  //Throughout the day simulation, this will print the status of the stores
  static std::string runDaySimulation(Date *datePtr, PizzaStore*, PizzaStore*);

  //given a pointer to a date object
  //will continue incrementing the date until it is sunday
  static void marchToSunday(Date* datePtr);

  //appends a line to log.txt with
  //"<dayofweek> <mm/dd/yyyy> <winner> won with <slicesLeft> slices left!"
  //If winner is a null pointer, then use it as a tie
  //"<dayofweek> <mm/dd/yyyy> Tie!"
  static void writeToFile(Date *datePtr, PizzaStore *winner);
  
  
};

#endif
