#include <iostream>

int factorial(int n);
int power(int a, int b);
int pins(int rows);
int fibonacci(int n);

int main() {
  std::cout<<"running recursive main\n";
  std::cout<<factorial(5)<<std::endl;
  std::cout<<power(2,4)<<std::endl;
  std::cout<<power(5,3)<<std::endl;
  std::cout<<pins(10)<<std::endl;
  std::cout<<"fibo: "<<fibonacci(84);
  std::cout<<"goodbye recursion\n";
}


int factorial(int n) {

  if(n>1) {
    return n*(factorial(n-1)); //recursive call
  } else {
    return 1; //base case
  }

}

int power(int a, int b) {//a to the power of b 
  if(b>1) {
    return a*(power(a,b-1)); //recursive call
  } else {
    return a*b; //base case
  }
}

int pins(int rows) {
  if(rows==1) {
    return 1; //base case
  } else {
    return rows+pins(rows-1); //recursive call
  }

}

int fibonacci(int n) {
  int start = 1;

  if(n==0) {
    return 0;
  } else if(n==1) {
    return 1;
  } else {
    int a = fibonacci(n-1);
    int b = fibonacci(n-2);
    std::cout<<a<<" "<<b<<std::endl;//3rd fav 84
    return (a + b);

  }
  

}