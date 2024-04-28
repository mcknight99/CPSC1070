#include <iostream>
class Point{
public:
  int xCoord;
  int yCoord;
public:
  Point(int x, int y) {
    xCoord=x;yCoord=y;
  }
  void operator+(const Point& right) {
    xCoord+=right.xCoord;
    yCoord+=right.yCoord;
  }
};


int main() {
  Point a(4,3);
  Point b(6,7);
  a=a+b;
  std::cout<<a.xCoord<<" "<<a.yCoord<<std::endl;

}
