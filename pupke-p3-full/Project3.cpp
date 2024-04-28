#include <iostream>
#include "Queue.h"
#include "Cipher.h"
#include "CipherAdvanced.h"
#include <limits> //input validation limits
using namespace std;

int main() {
  //CipherAdvanced::lengthWordsFile(); //also calls filterWordFile if it doesnt already exist
  CipherAdvanced mca;
    
  mca.unknownMultiWordScramble("jgrqodttzxgxobjxlgfjnwwspqyuobjchnsemnmwqtkjkoerotuqnnbgzdetnqmwutgxzznjviextgjkzxgxwohc"); //key=computer, realtext=greatjobwiththefirstscramblethekeyforthenextpuzzlehastwowordswherethefirstrhymeswithbuck
  mca.unknownMultiWordScramble("wglaixpbyillvqvoddbiywyigphnxilfvzdvzhhmciw"); //slipsignedthankyounoteunderyouradvisorsdoor
  mca.unknownMultiWordScramble("gdlzhgvzwqxqmlxhjsjdwdaffzgwsscdt"); //nothingherebutyouaredoinggreatjob
  mca.unknownMultiWordScramble("ptgluyzwypukxbzuknlmisqigxubvbqxlkycdyswroikrrqxl"); //messageteachingassistantseajaywithjokeaboutsoccer
  mca.unknownMultiWordScramble("uczhrjngttziapgk");//oneplusoneequals
  std::cout<<"\n\n\nthe important one:\n";
  //mca.unknownMultiWordScramble("ycderehngdtlhbwxtddktmtkmmxbmajitcqlzumatbiyfdlifzjzvnmpljgdnttdpjyncz"); 
  mca.unknownMultiWordScramble("rxhslupmdab"); //catdogapple
  mca.unknownMultiWordScramble("sddtjbafsucdfyvcwvxfsbgdbhvbzerqlyz"); //the test case from gradescope  
  
  //mca.unknownMultiWordScramble("fpz");
  
  cout<<CipherAdvanced::binarySearch("via",CipherAdvanced::linesFiltered);
  
  string key = "";
  cout<<"Type in the word to use as the key: ";
  getline(cin, key);
  cout<<endl;
  string filteredKey = Cipher::inputValidation(key);

  char* filteredKeyPtr = &filteredKey[0];
  Cipher myCipher(filteredKey.length(), filteredKeyPtr);

  bool quit = false;
  
  do{//repeat the menu until quitting
    
    char choice = 0;
    string in = "";
    bool valid = false;
    do{
      cout<<"Key: "<<filteredKey<<endl;
      cout<<"[e] encode with that key\n";
      cout<<"[d] decode with that key\n";
      cout<<"[s] solver without a key\n";
      cout<<"[q] quit\n";
    
      cin>>in;
      choice=in[0];
      if(cin.good()&&in.length()==1) {
	valid=true;
      } else {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"Invalid input, please try again\n\n";
      }
    } while(!valid);

    switch(choice) {
    case 'e': case 'E': {
      string encode = "";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Enter what to encode: ";
      getline(cin, encode);
      encode = Cipher::inputValidation(encode);
      string resultEncode = myCipher.encodeMessage(encode);
      cout<<"result: "<<resultEncode<<endl<<endl;
      break;
    } //close case E
    case 'd': case 'D': {
      string decode = "";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Enter what to decode: ";
      getline(cin, decode);
      decode = Cipher::inputValidation(decode);
      string resultDecode = myCipher.decodeMessage(decode);
      cout<<"result: "<<resultDecode<<endl<<endl;
      break;
    } //close case D
    case 's': case 'S': {
      string solve = "";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"Enter what to solve: ";
      getline(cin, solve);
      solve = Cipher::inputValidation(solve);
      CipherAdvanced myCA;
      myCA.unknownMultiWordScramble(solve);
      break;
    }
    case 'q': case 'Q': {
      quit=true;
      break;
      default:
	cout<<"Invalid input, please try again\n";
	break;
    } //close case Q
    }

  } while(!quit);
}