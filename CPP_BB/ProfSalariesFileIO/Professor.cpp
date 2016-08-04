/*
Your program will read/deserialize the Professor objects out of a file, then sort the Professors by name, then filter the Professors, 
then only print or serialize the Professors to std::cout. 
The file or "database" to open will be argv[1], and each filter will consist of 3 arguments: the field name 
(for now we will only filter on the ".name" field), "less_than" or "greater_than", 
and finally the value (since we're only filtering on names, the value is a string like "Mario"). There may be 0, 1, or 2 filters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Professor.h"

using namespace std;

Professor::Professor() : Professor("John Doe", "Generic", 0, 0) {}

Professor::Professor(const Professor& other) { //works
    *this = other;
};

Professor::Professor(std::string name, std::string title, int base_pay, int total_pay) 
    : name(name), title(title), base_pay(base_pay), total_pay(total_pay) {}

Professor& Professor::operator=(const Professor& other){
    name = other.name;
    title = other.title;
    base_pay = other.base_pay;
    total_pay = other.total_pay;
    return *this;
};

// Used to compare Professors by name
bool Professor::operator<(const Professor& other) const { //will literally compare name < other.name
    return name < other.name;
};

bool Professor::operator>(const Professor& other) const { //will literally compare name > other.name
    return name > other.name;
};

//Seems like the two methods below are for writing (serialization) and reading (deserialization)
//https://isocpp.org/wiki/faq/serialization
// Serialize a Professor to a file (name, title, etc. on different lines)
// This outputs info to file, but on different lines
bool Professor::serialize(std::ostream& os) const {
    return os << *this;
    /*
    os << name;
    os << title;
    os << base_pay;
    os << total_pay;
    */
};

// Deserialize a Professor from a file (name, title, etc. on different lines)
//This reads info FROM a file
bool Professor::deserialize(std::istream& is) {
    return is >> *this;
    /*
    string sbase_pay, stotal_pay;
    
    getline(is, name, '\n');
    getline(is, title, '\n');
    getline(is, sbase_pay, '\n');
    getline(is, stotal_pay, '\n');
    
    base_pay = atoi(sbase_pay.c_str());
    total_pay = atoi(stotal_pay.c_str());
    */
};

// Read in a Professor, the same way you would from a file
std::istream& operator>>(std::istream& is, Professor& p) {
    string sbase_pay, stotal_pay;
    
    getline(is, p.name, '\n');
    getline(is, p.title, '\n');
    getline(is, sbase_pay, '\n');
    getline(is, stotal_pay, '\n');
    
    p.base_pay = atoi(sbase_pay.c_str());
    p.total_pay = atoi(stotal_pay.c_str());
    return is;
};
// Output a Professor so it looks like
// "Professor(\"Mikel Mcdaniel\", \"Part-Time Human\", 1000000, 1000001)"
std::ostream& operator<<(std::ostream& os, const Professor& p){
    os << "Professor(\""<< p.name << "\", " <<"\""<< p.title << "\", " << p.base_pay 
    << ", " << p.total_pay << ")" << endl; //Works in printing out the object
    return os;
};
    