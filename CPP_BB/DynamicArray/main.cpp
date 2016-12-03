#include <iostream>
#include <string>

#include "DynamicArray.h"

using namespace std;

int main() {
  DynamicArray<int> nums;
  DynamicArray<int> numbs;
  DynamicArray<string> str;

  nums.push_back(0);
  nums.push_back(5);
  nums.push_back(28);
  nums.push_back(51);
  nums.push_back(104);
  nums.push_back(201);
 
  for (const int& x : nums) {
    cout << x << endl;
  }
  cout << endl;

  numbs.push_back(11);
  numbs.push_back(22);
  numbs.pop_back();
  for (const int& x : numbs) {
      cout << x << endl;
  }
  cout << endl;
  
  nums.pop_back();
  nums[0] = '0';
  nums[1] = 'A';
  nums[2] = 'a';
  for (const int& x : nums) {
    cout << x << endl;
  }
  cout << endl;
  
  str.push_back("Hello");
  str.push_back("World");
  
  for (const string& x : str) {
      cout << x << endl;
  }
  cout << endl;
  
  
  
  return 0;


/* OUTPUT
12
34
56
78

48
65
97
*/
}