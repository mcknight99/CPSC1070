// Samuel Pupke (C16563633)
// Sep 22, 2023
// 
// How the game works
// 5 household products will be randomly chosen to be displayed to the player
// The range for scoring a bullseye, and thus winning the game, will be between $10 and $13
// The category for which set of products used in a game will be randomly determined
// Once a product has been used, it's out of play
// The contestant has three chances to select a product and choose the bids

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
//#include <set>
#include <limits> //173

using namespace std;

//function prototypes

//void runGame() // LAUNCH THE GAME 
void runGame();

//char runMenu() // RUNS THE MENU SYSTEM AND RETURNS THE USER'S CHOICE AS A CHARACTER
char runMenu();

//bool runBid(string items[5], double itemChosenResults[5]) // PROMPTS THE USER TO SELECT AN ITEM THAT HAS NOT ALREADY BEEN SELECTED, THEN PROMPTS FOR A MULTIPLE (use guessQuantity), AND FINALLY RETURNS TRUE IF THEY WON, FALSE IF NOT
bool runBid(string (&items)[5], double (&itemChosenResults)[5]);

//double getPrice(int min, int max) // RETURNS A RANDOM VALUE BETWEEN MIN AND MAX INCLUSIVE
double getPrice(int, int);

//int guessQuantity(string itemName) // PROMPTS THE USER TO GIVE A MULTIPLE OF itemName AND RETURNS THAT VALUE
int guessQuantity(string);

//void displayBoard(string items[5], double itemChosenResults[5]) //DOES A LOT OF SH!T
//displays the bullseye board populated appropriately with items.
//if an item is no longer available to be selected, the slot should be blank
//items should be left justified
//the target range should have a space between each number
//after each round, an X should be placed appropriately in the target range
//  if the total amount (after multiplying the price by the number of items) exceeds $20, an x should be placed to the above right of 20
//  otherwise, the X should be placed above the blank space between the two numbers in which the total amount lies (e.g. a total amount of $12.01 would have the X above the space between 12 and 13)
void displayBoard(string items[5], double itemChosenResults[5]);

// function unrelated to playing the game, but makes enabling and disabling extra cout statements quick and painless for debugging
bool debug(bool);




int main() {
  runGame();
  return 0;
}



void runGame() { //1
  static int gameCounter;
  bool changeConsole = false; //if we should ask the user if they want to enable extra console print, will be false for submission
  bool console = changeConsole? debug(changeConsole) : false; //default for debugging
  bool win = false; //if the user won
  bool quit = false;
  bool run = true;
  
  srand(time(0));
  
  
  int setLength = 4; //how long each set is -- wouldn't work in unbalanced 2d array, but thankfully this project doesn't require it. If it did, make this the maximum set length and have sentinel values for shorter sets to stop instead of going for the whole set
  int setAmount = 5; //how many sets there are
  //int bullseyeMin = 10;
  //int bullseyeMax = 13;
  
  
  int attemptsLeft = 3;

  //NEW IDEA TO MANAGE ITEMS: JUST MAKE 2 ARRAYS: randomItems and randomPrices. randomPrices uses the [i] of masterSet on priceRangeSety
  string masterSet[setAmount][setLength] = { //2
	{"Turkey","Ham","Chicken","Beef"},
	{"Apple", "Pear", "Grape", "Orange"},
	{"Water", "Soda", "Juice", "Tea"},
	{"Frame", "Candle", "Pillow", "Vase"},
	{"Popcorn", "Chips", "Cookies", "Granola"}
  }; //2
  double priceRangeSet[setAmount][2] = { //2
	{3,10},
	{1,3},
	{1,2},
	{3,5},
	{1,4}
  }; //2
  //I was thinking I may have needed to make a list of prices randomly generated in the priceRange, but because each object is only played once, I just have to randomly generate a price for it when it comes up for multiplying. Thinking about it, these arrays might not need to be in runGame(), but instead wherever their scope is needed in the functions later
  
  for(int i = 0; i<setAmount && console; i++) { //2
    cout<<"Set " << i << ": ";
    for(int j = 0; j<setLength; j++) { //3
      cout<<masterSet[i][j] << ", ";
    } //3
    cout<< "Price range: " << priceRangeSet[i][0] << "-" << priceRangeSet[i][1] <<endl;
  } //2


  while(run) {//RUN
    //cout<<"gameCounter= "<<gameCounter<<endl;
    gameCounter=gameCounter+1;
    //cout<<"gameCounter= "<<gameCounter<<endl;
    string items[] = {"","","","",""};
    double itemChosenResults[] = {0.0,0.0,0.0,0.0,0.0}; //store randomSetPrices*user multiple input here
    //double randomSetPrices[] = {0.0,0.0,0.0,0.0,0.0}; //each price of each item. set to 0 after using?
    for(int i = 0; i<5; i++) { //choose 5 items at random
      int jRand = static_cast<int>(getPrice(0,setLength-1)); //random col from the masterSet, using getPrice for a random number but cast to an int
      items[i] = masterSet[i][jRand]; //i is same from masterSet, one thing from each category
      //randomSetPrices[i] = getPrice(priceRangeSet[i][0],priceRangeSet[i][1]); //choose a random price between low and high bound from respective set price range
      if(console) {
	//cout<< "item " << i << " is " << items[i] << " ($"<< randomSetPrices[i]<<"), \n"; //now irrelevant because I had to remake the prices in getBid
      }
    }

  
  
    if(gameCounter==1) {
      cout<< "Welcome to the CPSC 1070 Bullseye!\n\nThe goal is to get between $10 and $13 by picking an item and a quantity. There are five items, but you only get three tries.";
    
      displayBoard(items, itemChosenResults); //i dont think randomSetPrices is the right input but its a placeholder i guess so the function can function (ha)
    }
    while(!quit){ //2
      cout<<attemptsLeft<<" attempt(s) left\n\n";

      char choice = runMenu(); //i put the menu code inside of runMenu for the edge case of the user not putting in a valid entry so it could run the switch code again and so I wouldn't have to use a GOTO like I wanted because that's probably also a no-no in this class
      bool reset = false;
  
      switch(choice) {
      case '1':
	//case 1 code, bid on an item
	if(attemptsLeft==0) {
	  cout<<"You've run out of attempts, reset to play more!\n";
	} else if(!win) {
	  win = runBid(items, itemChosenResults);
	  attemptsLeft--;
	
	  
	
	} else {
	  cout<<"You've already won, reset to play more!\n";
	}
	break;
      case '2':
	//case 2 code, display current board
	displayBoard(items,itemChosenResults);
	break;
      case '3':
	//case 3 code, restart game
	cout<< "Resetting...\n";
	reset=true;
	break;
      case '4':
	//case 4 code
	cout<<"Thank you for playing!\n\n";//dunno if this wants new line(s) but the examples show none
	quit=true;
	run = false;
	break;
      default:
	cout<<"Please input a valid menu selection\n";
	runMenu();
	break;
      }

      if(reset) {
	runGame();
	run=false;
	quit=true;
      }
    
    
      if(console){
	for(int i = 0; i<5; i++) {
	  cout<<items[i]<<", "<<itemChosenResults[i]<<endl;
	}
      }
  
    } //2
  }//RUN
}// 1







char runMenu() { //run the menu system and return the user's choice as a character
  char choice = '0';
  cout<<"---- CPSC 1070 Bullseye Menu ----\n\n\n[1] Bid on an item\n[2] Display current board\n[3] Restart the game\n[4] Quit\n\nYour choice?: ";
  cin>>choice;
  
  return choice;
}


//prompts the user to select an item that has not already been selected, then prompts for a multiple (use guessQuantity) and finally returns true if they won, false if not
bool runBid(string (&items)[5], double (&itemChosenResults)[5]) {//1 
  //priceRangeSet wasn't in the right scope so I cheesed it and just copied it over because it wasn't super long
  //if it were up to me, i would have had a third param in runBid so I could also pass in the prices so they were constant throughout the program because now the main scope ones become irrelevant
  double priceRangeSet[5][2] = { //2 //again with the passing things, if I could pass setAmount then I could use that here but I have to now keep it at just 5
	{3,10},
	{1,3},
	{1,2},
	{3,5},
	{1,4}
  }; //2

  //cout<<"Choose an item (1-5): ";
  int choice = -1;
  //cin>>choice;
  bool valid = false;
  do{
    cout<<"Choose an item (1-5): "<<flush;
    cin>>choice;
    if(cin.good() && (choice>0&&choice<6)) {
      valid = true;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Invalid input, please try again"<<endl<<endl;
    }
  } while(!valid);
  

  if((choice>0 && choice<6) && (itemChosenResults[choice-1]==0.0)) {//2

      
    double unitCost = getPrice(priceRangeSet[choice-1][0],priceRangeSet[choice-1][1]);
    //and if console could have been passed here too then i could have enabled or disabled the test cout statement so much easier
    //DISABLE THIS NEXT LINE DURING FULL GAME
    //cout<<items[choice-1] <<"$"<<unitCost<<endl;


    double multiples = guessQuantity(items[choice-1]);

    double totalCost = multiples*unitCost;//NOT GONNA WORK HOMBRE  //NOW IT WORKS HOMBRE
    itemChosenResults[choice-1]=totalCost;
    cout<<endl<<items[choice-1]<<" has a unit cost of $"<<unitCost<<", so the total price is $"<<totalCost<<". ";
    if(10 < totalCost && 13 > totalCost) { //again again with not being able to pass what i want and be flexible, i have to use hard coded values instead of bullseyeMin and bullseyeMax
      cout<<"Which is between 10 and 13!\nCongrats!!!\n";
      return true;
    } else {
      cout<<"Which unfortunately is not between $10 and $13"<<endl;//also why cant the outputs be consistent with each other, why does this have dollar signs but the win statement doesnt
      return false;
    }
    
  } else { //2
    //shouldn't have to run anymore with input validation
    cout<< "Invalid input, please try again\n\n";
    runBid(items, itemChosenResults);
  } //2


  
  return false;
} //1


double getPrice(int min, int max) { //returns a random value between min and max; inclusive
  min*=100;
  max*=100;
  return (double)((rand()%(max-min+1))+min)/100;
}

int guessQuantity(string itemName) {//sorta kinda really useless bc its only used once and its super easy to go without this function because i wrote the code for this in the function i was using it in anyways and didnt need a function for it so ew
  //float multiples = 0;
  
    double input = -1;
    bool valid = false;
    do{
      cout<<itemName<<" is selected. How many?: "<<flush;
      cin>>input;
      if(cin.good() && input>0) {
	valid=true;
      } else {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"Invalid input, please try again"<<endl<<endl;
      }
    } while(!valid);
  
  return input;
}

void displayBoard(string items[5], double itemChosenResults[5]) {
  string guessBar = "                            |        |                       "; //61 characters
  cout<<"\n\n-----------------------------------------\n|   1   |   2   |   3   |   4   |   5   |\n|";
  for(int i = 0; i<5; i++) {
    if(itemChosenResults[i]==0.0) {
      cout<< left << setw(7) << items[i] <<"|";
    } else {
      /*
      float x3 = static_cast<int>(itemChosenResults[i]); //whole num of guess only
      float x = itemChosenResults[i]-x3; //decimal of guess only
      int y = (x3*3)-2; //the slot we have to replace in guessBar
      //ex: guess = 12.72
      // x3 = 12
      // x = .72
      // y = (12*3)-2 = 34
      // x is 0,1,2 --> 2
      if(0<=x<0.3) {
	y+=0;
      } else if(0.3<=x<0.6) {
	y+=1;
      } else if(0.6<=x<1) {
	y+=2;
      }
      y+=3;
      */

      // THESE ARE THE LINES THAT I LIKE
      //int y=static_cast<int>(3 * itemChosenResults[i])-2; //okay what SOB decided that the example cases should be less accurate than this elegant solution here which is 3x as accurate >:|
      int intega = floor(itemChosenResults[i]);
      double decimul = itemChosenResults[i]-intega;
      int y = (3*intega)+floor(3*decimul);
      //14.29 * 3 = 42.87
      //14.02 * 3 = 42.06
      //we want it in 41-42
      
	//y+=1; //sometimes if the result is exactly .00, it will be one place to the left, so this fixes that
      
      // TO HERE
      
      //int y = static_cast<int>(itemChosenResults[i])*3; //THIS IS THE LINE THEY WANT FOR SUBMISSION
      if(y<61) {
	guessBar = guessBar.substr(0,y) + "X" + guessBar.substr(y+1);
      } else {
	guessBar = guessBar.substr(0,60) + "X";
      }
      cout<< left <<"       |";
    }
  }
  cout<<endl;
  /*
  cout<< left << setw(7) << items[0] <<"|";
  cout<< left << setw(7) << items[1] <<"|";
  cout<< left << setw(7) << items[2] <<"|";
  cout<< left << setw(7) << items[3] <<"|";
  cout<< left << setw(7) << items[4] <<"|\n"; */
  cout<<"|   1   |   2   |   3   |   4   |   5   |\n-----------------------------------------\n\n";
  //TESTING NEXT LINE
  //guessBar[5]="x";
  //doesnt work unfortunately, so next logical conclusion is substringing, then an annoying array of spaces if that doesnt work
  //guessBar = guessBar.substr(0,5) + "x" + guessBar.substr(6);
  
  
  
  
  cout<<guessBar<<endl;
  
  cout<<"  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 \n\n"; //61 characters
  
}


bool debug(bool change) { //1
  if(change) { //2
    cout<<"print extra to console? (y/n, default n): ";
    char in = 'n';
    cin>>in;
    in=tolower(in);
    switch(in) { //3 //very silly use of switch bc it could just be if y else but i was messing around with switch 
    case 'y':
      return true;
      break;
    case 'n':
      return false;
      break;
    default:
      return false;
      break; 
    } //3  
  } //2
  return false;
}//1
