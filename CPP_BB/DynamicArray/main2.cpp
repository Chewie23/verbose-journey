#include <iostream>

#include "DynArr.h"

using namespace std;

int main() {
  int array[5];
  int* arptr;
  arptr = array;
  arptr[0] = 4;
  arptr[1] = 5;
  cout << *arptr << endl;
  cout << sizeof(*arptr)/sizeof(*arptr);
  return 0;
}