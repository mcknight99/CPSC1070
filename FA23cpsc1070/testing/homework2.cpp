#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include <vector>
using namespace std;

void printTriangle();
double averageWeeklyNoonTemp(int[7][24]);
void jazzhands();

int main() {
  unsigned seed = time(0);
  srand(seed);
const int numRows = 7;
const int numCols = 2;
int total;
string weekend[] = {"Saturday","Sunday"};
int wkEndHrs[numRows][numCols] = {{8,0},{0,17},{5,6},{8,2}};
//what will each display?
for(int row = 0; row < numRows; row++) {
  total = wkEndHrs[row][0] +  wkEndHrs[row][1];
  //  cout<<(row+1)<<"\t"<<total<<endl;
 }

for(int col = 0; col < numCols; col++) {
  total=0;
  for(int row = 0; row<numRows; row++) {
    total+=wkEndHrs[row][col];
  }
  //cout<<weekend[col]<<"\t"<<total<<endl;
 }
 



 //enum Department {Purchasing, Manufacturing, Warehouse, Sales};
 //Department floor1, floor2;
 //int dNum = 2;
 //floor 1 = Sales; //no work
 //dNum = Sales;
 //dNum = floor1;
 //floor2 = dNum; //no work


 
// printTriangle();
/*
int temperatures[7][24] = {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
			    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
*/
 for(int i = 0; i<7; i++) {
   for(int j = 0; j<24; j++) {
     //temperatures[i][j] = rand()%24;
     //cout<<setw(2)<<temperatures[i][j]<<", ";
   }
   //cout<<endl;
 }

 //cout<<averageWeeklyNoonTemp(temperatures)<<endl;











 //jazzhands();
 return 0;
}




void printTriangle(){
  int rows = 7;
  int cols = 7;
  int triangle[rows][cols] = {{1,0,0,0,0,0,0},
			{1,1,1,0,0,0,0},
			{1,1,1,1,1,0,0},
			{1,1,1,1,1,1,1},
			{1,1,1,1,1,0,0},
			{1,1,1,0,0,0,0},
			{1,0,0,0,0,0,0}};
  for(int row = 0; row<rows; row++) {
    for(int col = 0; col<cols; col++) {
      if(1==triangle[row][col]) {
	cout<<"+";
      }
    }
    cout<<endl;
  }

}//main closer


double averageWeeklyNoonTemp(int temps[7][24]) {
  double total = 0.0;
  for(int i = 0; i<7; i++) {
    total+=temps[i][12];
    cout<<temps[i][12]<<", "<<total<<endl;
  }
  return total/7;
}



void jazzhands() {
  vector <int> x(1000,0);
  for(int i = 0; i<1000; i++) {
    x[i] = 1000-i;
    cout<<x[i]<<", ";
  }
  cout<<endl;
  cout<<x[999]<<" "<<x[998]<<" "<<x[1]<<" "<<x[0]<<endl;
}
