#include <cassert>
#include <iostream>
#include "bag.h"

using namespace std;

int main() {
  //tests if it prints
  Bag<int> a;
  for (int i = 0; i < 8; i++){
      a.insert(i);
  }
  a.debug_info("a");

  //#1 Copy constructor
  Bag<int> b(a);
  b.debug_info("b");

  //#2 testing assignment operator
  Bag<int> buggie;
  for (int j = 0; j < 10; j++){
      buggie.insert(j);
  }
  buggie.debug_info("buggie");

  a=buggie;
  a.debug_info("a");

  //#3 Union assignment
  Bag<int> c;
  for (int i = 8; i >= 0; i--){
      c.insert(i);
  }
  c.debug_info("c");

  a+=c;
  a.debug_info("a");

  //#4 Swap
  a.swap(c);

  c.debug_info("c");
  a.debug_info("a");
  return 0;
}
