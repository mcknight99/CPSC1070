#include <iostream>
using namespace std;

//function prototypes
void masterCount(int);
void henryCount(int);

int valueParam(int, int);
int referenceParam(int&, int&);

int main(){
  cout<<"Starting a demo!"<<endl;

  int a = 13;
  int b = 666;

  henryCount(a);
  cout<<"After henryCount a is "<<a<<endl;
  henryCount(a);
  cout<<"After 2nd henryCount a is "<<a<<endl;
  //result = valueParan(a,b);

  masterCount(a);
  cout<<"After masterCount a is "<<a<<endl;
  masterCount(a);
  cout<<"After 2nd masterCount a is "<<a<<endl;


  int result = valueParam(a,b);
  cout<<"result after valueParam is "<<result<<endl;
  cout<<"a after valueParam is "<<a<<endl;
  cout<<"b after valueParam is "<<b<<endl;


  
  int result2 = referenceParam(a,b);
  cout<<"result after valueParam is "<<result2<<endl;
  cout<<"a after valueParam is "<<a<<endl;
  cout<<"b after valueParam is "<<b<<endl;

  //referenceParam
  //masterCount

  cout<<"Goodbye World!"<<endl;

}



void henryCount(int inNum) {
  inNum++;
  int h = inNum;
  cout<<"henryCount h is "<<h<<endl;
}



void masterCount(int inNum) {
  static int counter;
  counter = inNum;

  //versus
  static int counter2;
  counter2 += inNum;
  cout<<"masterCount counter is "<<counter<<endl;
  cout<<"masterCount counter2 is "<<counter2<<endl;
}



int valueParam(int inA, int inB) {
  inA++;
  inB++;
  return inA+inB;
}


int referenceParam(int &inA, int &inB) {
  inA++;
  inB++;
  return inA+inB;
}