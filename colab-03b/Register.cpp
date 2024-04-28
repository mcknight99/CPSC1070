#include "Register.h" //includes vector and string


Register::Register(){//default constructor
  fileName="";
}

std::string Register::getFileName() {
  return fileName;
}

void Register::setFileName(std::string stringIn) {
  fileName=stringIn;
}

bool Register::processTransaction() { //driver for register. calls the other methods. returns true if successful, false otherwise
  bool valid=false;
  int failCounter = 0;
  std::string fileIn = "";
  do{
    std::cout<<"\tPlease enter the filename: ";
    std::cin>>fileIn;
    setFileName(fileIn);
    std::cout<<"\tOpening the file <"<<fileIn<<">\n";
    if(std::cin.good() && readFromFile()) {
      valid=true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout<<"Error opening file. Please retry.\n";
      failCounter++;
      if(failCounter==5) { //testing if this was the error but it wasnt 
	//std::cout<<"nah no way you failed typing it in 5 times. (also to prevent softlocking in this spot without changing the output of the program i made a silent fail 5 times to quit this because they didnt include a way to get out if you dont have a file or want to cancel\n";
	//return false;
      }
      
    }
  } while(!valid);
  printFile();

  valid=false;

  char choice = 'i';
  do{
    std::cout<<"Would you like to process another transaction register? (y/n): ";
    std::string stringIn = "i";
    std::cin>>stringIn;
    if(stringIn.length()==1) {
      //      choice=*stringIn.c_str();//learned from c++.com
      choice=stringIn.at(0);
    }
    switch(choice){
    case 'y' : case 'Y':
      processTransaction();
      valid=true;
      break;
    case 'n': case 'N':
      std::cout<<std::endl;
      valid=true;
      break;
    default:
      std::cout<<"Invalid Input! Please choose again."<<std::endl;
      break;
    }
  } while(!valid);



  return true;
}

bool Register::readFromFile() { //input variables are separated by spaces, can use >> >>
  std::ifstream inputFile(fileName);
  
  if(!inputFile) {
    return false;
  }

  //because of appending values, we don't want to flood over from any previous runs
  fileInput.clear();
  dates.clear();
  types.clear();
  locations.clear();
  amounts.clear();

  std::string line;
  while(std::getline(inputFile, line)) { //while we can get a line from the input file
    std::istringstream iss(line); //using istringstream to grab a whole line
    std::vector<std::string> row; //store a vector of strings
    std::string value; //store one at a time

    while(iss>>value) {//while we can take a new value from iss
      row.push_back(value); //append value to the end of the row vector
    }

    fileInput.push_back(row); //append the row to the 2d fileInput vector
  } //while getline closer

  inputFile.close();

  for(std::vector<std::string> row : fileInput) {  //turning the 2d fileInput into corresponding rows for easier comprehension in stored variables
    dates.push_back(row[0]);
    types.push_back(row[1]);
    //enumeratedTypes.push_back(enumTransactions[std::find(TransactionsList.begin(), TransactionsList.end(), row[1]]); //find where the input transaction type is, and add the corresponding enum to enumeratedTypes //ended up being more work than it was worth
    locations.push_back(row[2]);
    amounts.push_back(row[3]);
  }
  
  return true;
}

void Register::printFile() {

  /*
  for(std::vector<std::string> row : fileInput) { //unformatted printfile
    for(std::string value : row) {
      std::cout<<value<<" ";
    }
    std::cout<<std::endl;
  }
  */
  std::cout<<"Printing Transaction Ledger\n";
  for(int i = 0; i<dates.size(); i++) {
    std::cout<<std::right<<std::setw(10)<<dates[i]<<" |";
    std::cout<<std::right<<std::setw(15)<<locations[i]<<" |";
    std::cout<<std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<std::stod(formatMoney(amounts[i]))<<" |";
    std::cout<<std::right<<std::setw(20)<<toTitleCase(types[i])<<std::endl<<std::endl;
    
  }
  
}


std::string Register::toTitleCase(std::string stringIn) {
  std::string stringOut = stringIn.substr(0,1);
  for(int i = 1; i<stringIn.length(); i++) {
    char letter = stringIn.at(i);
    stringOut+=tolower(letter);
  }
  return stringOut;
}

std::string Register::formatMoney(std::string stringIn) {
  std::string stringOut = stringIn;
  while(stringOut.substr(0,1)=="+") {
    stringOut=stringOut.substr(1);//gets rid of those pesky plus signs. 
  }
  //dont know exactly why i wrote this but i was feeling like writing some functions tonight
  return stringOut;
}
