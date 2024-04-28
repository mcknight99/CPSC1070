#include <iostream>
#include <string>

using namespace std;

class BakedGood{
private:
  string good;
public:
  BakedGood(){cout<<"BakedGood constructor!"<<endl; good="generic";};
  BakedGood(string name) {good = name;};
  ~BakedGood() {cout<<"\tBakedGood destroyed!"<<endl;};
  void print() {cout<<"I'm a "<<good<<endl;};
  string get(){return good;};

  };


  int main(){
    BakedGood bg1;
    BakedGood bg2("cookie");
    BakedGood pie1("chocolate silk");
    {
      BakedGood cake0;
      {
	BakedGood pie2("key lime");
	pie2.print();
      }
    }
    BakedGood cake1("buttercream");
    bg2.print();
    cake1.print();




  }
