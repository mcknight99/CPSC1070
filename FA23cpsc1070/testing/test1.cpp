#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

int main() {

  srand(time(0));
  int random = rand()%10+1;
  std::cout<<random<<std::endl;
  std::vector<int> vectah(random);
  for(int i = 0; i<random; i++) {
    vectah[i] = random-i;
  }
  for(int i = 0; i<random; i++) {
    std::cout<<vectah[i]<<", ";
  }
  
  return 0;
}
