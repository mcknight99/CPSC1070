#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include <string> //strings
#include <vector> //vectors
#include <iostream> //io to terminal
#include <iomanip> //setw and right
//#include "Date.h"
#include <cstdlib> //random number generation
#include <ctime> //rng seeding

class PizzaStore{
 public:
  PizzaStore();
  PizzaStore(std::string name, int maxPizzas, double productionPerTick, double successRate);
  int tickUpdate(); //bakes & adds pizzas
  bool consumeSlices(int slices); //returns false if the order could not be satisfied
  void showStatus(); //show how many slices each pizza has. Ex: "Core: 0 4 8"
  std::string getName();
  int getTotalSlicesLeft();

private:
  std::string name;
  int maxPizzas;
  double productionPerTick;
  double successRate;
  std::vector<int> slices;
  int sumVector(std::vector<int> vectorIn);
};

#endif
