#pragma once

#include <iostream>
#include <string>

class Professor {
public:
  std::string name, title;
  int base_pay, total_pay;

  Professor();//default constructor
  Professor(const Professor& other); //copy constructor
  Professor(std::string name, std::string title, int base_pay, int total_pay); //constructor defining the member variables

  Professor& operator=(const Professor& other); //overloading "=" operator

  // Used to compare Professors by name
  bool operator<(const Professor& other) const;
  
  bool operator>(const Professor& other) const;

  //Seems like the two methods below are for writing (serialization) and reading (deserialization)
  //CAN be txt file, but let's go for binary. Because I like extra steps
  //https://isocpp.org/wiki/faq/serialization
  // Serialize a Professor to a file (name, title, etc. on different lines)
  // This outputs info to file
  bool serialize(std::ostream& os) const;
  
  // Deserialize a Professor from a file (name, title, etc. on different lines)
  //This reads info FROM a file
  bool deserialize(std::istream& is);

  //Guess what? Gotta define the two friend functions below in Prof.cpp
  // Read in a Professor, the same way you would from a file
  friend std::istream& operator>>(std::istream& is, Professor& p);
  // Output a Professor so it looks like
  // "Professor(\"Mikel Mcdaniel\", \"Part-Time Human\", 1000000, 1000001)"
  friend std::ostream& operator<<(std::ostream& os, const Professor& p);
};