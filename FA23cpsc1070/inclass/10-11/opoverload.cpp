#include "overload.h"

//overloaded operators

Length operator+ (Length a, Length b) {
  return Length(a.len_inches+b.len_inches);
  //return a new length object to match length type
}

Length operator- (Length a, Length b) {
  return Length(a.len_inches-b.len_inches);
  //return a new length object to match length type
}

bool operator< (Length a, Length b){
  return (a.len_inches<b.len_inches);


}

bool operator== (Length a, Length b) {
  return (a.len_inches==b.len_inches);


}
