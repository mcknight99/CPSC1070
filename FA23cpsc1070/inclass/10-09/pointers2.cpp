#include <iostream>
using namespace std;
void bFunction();

int main(){
  bFunction();
  return 0;
}


void bFunction(){
  int values[10] = {-2,-1,0,1,2,3,4,5,6,7};
  char word[30] = {'l','o','t','t','a','p','o','i','n','t','e','r','s','!'};
  int i = 0;
  int j = 10;

  int *ptr1 = values;
  cout<<"size of int: "<<sizeof(int)<<endl;
  cout<<"item 1.0: ptr1 = "<<ptr1<<endl;
  cout<<"item 1.0: ptr1+1 = " <<ptr1+1<<endl;
  cout<<"item 1.1: *ptr1 = "<<(*ptr1)<<endl;
  cout<<"item 1.2: *ptr1+3 = "<<*ptr1+3<<endl;

  int *ptr2 = ptr1+3;
  cout<<"item 2: ptr2 = "<<*ptr2<<endl;

  char *ptr3 = word;

  cout<<"item 3: *ptr3 = "<<*ptr3<<endl;
  cout<<"item 4: *ptr3(+4)="<<*(ptr3+3)<<endl;

  char *ptr4 = word;
  for (i = 0; i<6; i++) {
    cout<<*ptr4<<" ";
    ptr4+=3;
  }
  cout<<endl<<"item 6: "<<word<<endl;

}
