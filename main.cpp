#include <iostream>
#include "myclass.h"
#include "myclass.cpp"
using namespace std


int main() {
  MyClass myObj(15, "Some text");
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}
