#include "PizzaWars.h"



PizzaWars::PizzaWars() {

}

//public driver function for the entire PizzaWars simulation
void PizzaWars::runSimulation() {
  srand(time(0));
  std::cout<<"Welcome to Pizza Wars!\nThis program simulates an epic battle between Core and Schilletter and their ability to keep up with the demand for pizza!\n\nPlease enter the date you'd like to start the simulation in MM DD YYYY format: ";
  int MM,DD,YYYY;
  std::cin>>MM>>DD>>YYYY;
  Date inDate(MM,DD,YYYY);
  if(inDate.getDayOfWeek()!="Sunday") {
    std::cout<<"That day is not a Sunday, so we're moving to the nearest future Sunday to start\n";
  }
  Date* datePtr = &inDate;
  marchToSunday(datePtr);
  std::cout<<"Starting on "<<(*datePtr).toString();
  datePtr = allocateWeekOfDates(inDate);
  runSeriesSimulation(datePtr, 7);

  delete[] datePtr; //a new Date[] was created to point to in allocateWOD, so this deallocates
  std::cout<<std::endl;
}

//dynamically allocates & fills a date array with 7 days starting with the date passed in the parameter
  //return should point to the first date in the 7 day array
Date* PizzaWars::allocateWeekOfDates(Date date) {
  Date* week = new Date[7]; //memory that doesnt get deleted when the week goes out of scope so the pointer can point to any date in the week array
  for(int i = 0; i<7; i++) {
    week[i]=date+i;
  }

  return week;
}

// given an array of dates, will iterate through each day and call
  // runDaySimulation with it. writes the results from runDaySimulation
  //to the log.txt using writeToFile
void PizzaWars::runSeriesSimulation(Date *dates, int length) {
  PizzaStore core("Core", 3, 2, 0.9);
  PizzaStore schilletter("Schilletter", 6, 1, 0.8);
  
  std::ofstream outputFileClear("log.txt", std::ios::out | std::ios::trunc); //clear the output file from any previous simulations, not entirely sure I could recreate this without the documentation but this was cplusplus.com
  outputFileClear.close();
  
  for(int i = 0; i<length; i++) {
    Date* dayPtr = &(dates[i]); //pointing to a value in the dates array pointer
    std::string results = runDaySimulation(dayPtr, &core, &schilletter);
    if(results=="TIE!") {
      std::cout<<results;  
    } else {
      std::cout<<results<<" wins!";
    }
    
  }

}

//Determines whiich of the two pizza stores win
  //Returns the name of the store which won
  //Throughout the day simulation, this will print the status of the stores
std::string PizzaWars::runDaySimulation(Date *datePtr, PizzaStore *Store1ptr, PizzaStore *Store2ptr) {
  std::string stringOut = "error, achievement unlocked: hat";
  PizzaStore Store1 = *Store1ptr;
  PizzaStore Store2 = *Store2ptr;
  std::string day = (*datePtr).getDayOfWeek();
  bool simulate = true;
  int time = 0; //time runs from 0-19 or -21 depending on weekend or week day. each step represents 30 mins from 11am

  std::cout<<"\n\n\nRunning simulation for " << day << " " << (*datePtr).toString()<<std::endl<<std::endl<<std::endl;

  auto now = std::chrono::system_clock::now(); //i will admit i dont know exactly how auto or the chrono works, but i get the gist and it fixes my issue, I used cplusplus.com/forum/general/198490 and cplusplus.com/reference/chrono
  auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
  auto currentTimeInMillis = ms.time_since_epoch().count();
  
  while(simulate) {//a while loop to keep simulating until an end case is reached, but presumably should return before the end of it anyways

    //TIME RELATED CODE
    usleep(50000);// sleep for 0.05 sec
    now = std::chrono::system_clock::now();
    ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    currentTimeInMillis = ms.time_since_epoch().count(); //re recording the current time for a new seed
    srand(currentTimeInMillis); //basically the problem was the program ran too fast and randomizing within the same second doesnt change a random value so i had to reseed faster than a second otherwise every day would have the same results for some reason
    int hour = 11+(time/2);
    if(hour>12) {
      hour-=12; //no 24h time
    }
    std::string mins = (time%2==0)?"00":"30"; //yes i've been using more ternary operators because it is silly and i like them
    std::cout<<std::to_string(hour)<<":"<<mins<<std::endl;

    time++; //increment by 30 mins once we're done with time things

    //CONSUME AND CHECK RELATED CODE
    int consume1 = (std::rand()%16)+5; //calculating the consumed slices independently
    int consume2 = (std::rand()%16)+5;
    std::cout<<consume1<<" slice(s) are consumed at "<<Store1.getName()<<std::endl;
    std::cout<<consume2<<" slice(s) are consumed at "<<Store2.getName()<<std::endl;
    bool check1 = Store1.consumeSlices(consume1); //check if the store could eat all those slices
    bool check2 = Store2.consumeSlices(consume2);
    simulate = simulate && check1 && check2;
    (Store1).showStatus();
    (Store2).showStatus();
    
    if(!check1 && !check2) { //if both dont have enough
      writeToFile(datePtr,  nullptr);
      return "TIE!";
    } else if(!check1 && check2) { //if store 2 has enough and 1 doesnt
      writeToFile(datePtr, &Store2);
      return Store2.getName();
    } else if(check1 && !check2) { //if store 1 has enough and 2 doesnt
      writeToFile(datePtr, &Store1);
      return Store1.getName();
    } //i bet i can turn this entire if else if else if into a ternary in one big return operator if i reaeeeallllyy wanted to 

    //BAKE AND REPRINT RELATED CODE
    //to make this ieiei chain even more cursed we could wrap it with an if(!(check1||check2)) {ieiei} but thats too goofy
    std::cout<<Store1.tickUpdate()<<" pizza(s) were added at "<<Store1.getName()<<std::endl;
    std::cout<<Store2.tickUpdate()<<" pizza(s) were added at "<<Store2.getName()<<std::endl;
    (Store1).showStatus();
    (Store2).showStatus();
    std::cout<<std::endl;
   
    simulate = simulate &&((day == "Saturday" || day == "Sunday") ? time<19 : time<21); //if it is a weekend, evaluate if the time is before 8:30. if it is a weekday, evaluate if the time is before 9:30
    if(!simulate) { //if simulate ever became false and it didn't already return a special case, return a tie --> will be because of a timeout
      writeToFile(datePtr, nullptr);
      return "TIE!";
    }
  }//end of while loop
  
  return stringOut;
}

//given a pointer to a date object
  //will continue incrementing the date until it is sunday
void PizzaWars::marchToSunday(Date *datePtr) {
  while(((*datePtr).getDayOfWeek()).compare("Sunday")) {
    (*datePtr)++;
  }

}

//output to log.txt
//appends a line to log.txt with
  //"<dayofweek> <mm/dd/yyyy> <winner> won with <slicesLeft> slices left!"
  //If winner is a null pointer, then use it as a tie
  //"<dayofweek> <mm/dd/yyyy> Tie!"
  
void PizzaWars::writeToFile(Date *datePtr, PizzaStore *winner) {
  std::ofstream outputFile("log.txt", std::ios::app); //open in append mode, from c++.com
  
  if(outputFile.is_open()) {
    //default formatting of day and date
    outputFile<<std::left<<std::setw(10)<<(*datePtr).getDayOfWeek(); 
    outputFile<<std::setw(10)<<(*datePtr).toString(); // very bad formatting from whoever wanted it like this IMO, should either be setw 11 or a space after the date so there's always a gap between the result and the date
    if(winner==NULL) {//make sure that the pointer isn't null
      outputFile<<"Tie!"<<std::endl; //tie if the pointer is null
    } else {
      outputFile<<(*winner).getName()<<" won with "<<(*winner).getTotalSlicesLeft()<<" slices left!"<<std::endl;
    }
    outputFile.close();
  } else {
    std::cout<<"failure to open file !?!?!?"; //never happened thankfully
  }

}

