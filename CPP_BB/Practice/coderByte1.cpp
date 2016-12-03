//random practice
#include <iostream>
#include <vector>
using namespace std;

//Using the C++ language, have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. 
// example input:  coderbyte
// example output: etybredoc
string FirstReverse(string std) {
    vector<char> char_array;
    for (char & c : std) {
        char_array.insert(char_array.begin(), c); //Just rebuilds the string. Need to insert at front of vector
    }
    string str(char_array.begin(), char_array.end());
    return str;
}

int main() {
    string std;
    std = "I Love Code";
    cout << std << endl;
    cout << FirstReverse(std) << endl;
    
}