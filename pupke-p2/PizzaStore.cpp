#include "PizzaStore.h"


PizzaStore::PizzaStore() {

}

PizzaStore::PizzaStore(std::string nameIn, int maxPizzasIn, double productionPerTickIn, double successRateIn) {
  name=nameIn;
  maxPizzas=maxPizzasIn;
  productionPerTick=productionPerTickIn;
  successRate=successRateIn;
  std::vector<int> filler(maxPizzas, 8); //temporary "filler" to make the slices vector correctly without touching it until initialization
  slices = filler;
}

//bakes and adds pizzas to the pizza store
int PizzaStore::tickUpdate() {
  int pizzasToAdd = 0;
  for(int i = 0; i<productionPerTick; i++) { //for each pizza the store can produce per tick
    int rand = (std::rand()%100)+1; //produce a random number that will be between 1 and 100
    if(rand<=(successRate*100)) { //if the random number passes the success rate of the store
      pizzasToAdd+=1; //add a new pizza
    }
  }
  int pizzasAdded=0; //if the code decides it should produce more than it can hold
  for(int i = 0; i<static_cast<int>(slices.size()) && pizzasToAdd>0; i++) {  //static casting the size to get rid of -Wall errors to compare an int instead of vector<int>::sizetype
    if(slices[i]==0) { //try to add a pizza in an empty slot 
      slices[i] = 8; //add a pizza if we can
      pizzasToAdd--; //remove a pizza we have to add
      pizzasAdded++; //add a pizza we added
    }
  }
  return pizzasAdded; //not sure this is what it wants but?? it could work pretty nicely actually at least
}

//try to remove slices from the pizzastore 
//returns false if the order could not be satisfied
bool PizzaStore::consumeSlices(int slicesIn) {
  if(sumVector(slices)<slicesIn) { //if the amount of slices demanded exceeds amount remaining
    for(int i = 0; i<static_cast<int>(slices.size()); i++) {
      slices[i]=0;
    }
    return false; //return a false to consuming the slices
  } else {
    int i = 0;
    while(slicesIn>0) { //clever way to consume slices
      if(slices[i]>0) { //if there are still slices on the current pizza
	slices[i]--; //remove a slice from the current pizza
	slicesIn--; //remove a slice from the demand
      } else { //if there arent still slices 
	i++; //move to the next pizza
      }
    }
    return true;
  }
  std::cout<<"achievement unlocked: how did we get here?"<<std::endl; //hopefully the code never reaches this and if it does it has a very special error code that i know where an error happened, thankfully this never happened
  return false;
}

//prints with according spacing the name and each pizza
//ex:                Core: 0 5 8
void PizzaStore::showStatus() {
  std::cout<<std::right<<std::setw(20)<<name<<":";
  
  for(int i = 0; i<static_cast<int>(slices.size()); i++) {
    std::cout<<" "<<slices[i];
  }
  std::cout<<std::endl;
}

std::string PizzaStore::getName() {
  return name;
}

int PizzaStore::getTotalSlicesLeft() {
  return sumVector(slices);
}


  //so i had this code written before ever looking at getTotalSlices left, and when i went to write gTSL, i was like wait i already have this code. so i copy pasted what's below and it didnt work when i replaced vectorIn with slices, so i decided to keep this function and call the sumVector in gTSL
  //also this function is private while gTSL is public so this cant be used externally while gTSL can 
int PizzaStore::sumVector(std::vector<int> vectorIn) {
  int out = 0;
  for(int i = 0; i<static_cast<int>(vectorIn.size()); i++) {
    out+=vectorIn[i];
  }
  return out;

}
