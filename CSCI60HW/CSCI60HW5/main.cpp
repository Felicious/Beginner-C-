#include <cassert>
#include <iostream>
#include "bag.h"

using namespace std;

int main() {
  Uniquebag<int> uniquebag;
  uniquebag.debug_info("uniquebag");

  for (int i = 0; i < 10; ++i) uniquebag.insert(i % 2);
  uniquebag.debug_info("uniquebag");

  cout << "uniquebag.size() = " << uniquebag.size() << endl;
  cout << "uniquebag.count(0) = " << uniquebag.count(0) << endl;

  uniquebag.erase_one(0);
  uniquebag.debug_info("uniquebag");

  cout << uniquebag.erase(1) << endl;
  uniquebag.debug_info("uniquebag");

  Uniquebag<int> uniquebag2 = uniquebag;
  uniquebag2.insert(9);

  uniquebag.debug_info("uniquebag");
  uniquebag2.debug_info("uniquebag2");

  uniquebag2 = uniquebag;
  uniquebag2.debug_info("uniquebag2");

  Uniquebag<int> uniquebag3;
  for (int i = 10; i < 20; ++i) uniquebag3.insert(i);
  uniquebag3.debug_info("uniquebag3");
  uniquebag += uniquebag3;
  uniquebag.debug_info("uniquebag");

  Uniquebag<int> uniquebag4 = uniquebag + uniquebag2;
  uniquebag4.debug_info("uniquebag4");

  return 0;
}
