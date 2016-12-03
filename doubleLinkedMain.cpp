#include <iostream>

#include "doubly_linked_list.h"

// Simple main program that tests that the following methods work:
// DoublyLinkedList();  // default constructor
// DoublyLinkedList::push_back;
// DoublyLinkedList::begin();
// const T&amp; iterator::operator*() const;
int main() {
  DoublyLinkedList<std::string> mylist = {"one", "two", "three"};
  DoublyLinkedList<std::string>::iterator myiterator = mylist.end();

  mylist.print_list();
 
  myiterator = mylist.erase(myiterator); //this works as expected.
  mylist.print_list();
  
  std::cout 
  << "************************"
  << "\nInserting 'four' at end"
  << "\n************************" 
  << std::endl;
  
  
  mylist.print_ends();
  
  mylist.insert(mylist.end(), "four"); //this seems to shift pointers around. Why?
  //technically it DOES work, just somehow got head pointer mixed up in all this
  std::cout << "\n===========Printing list from main===========" << std::endl;
  mylist.print_list();
  
  
  /*
  myiterator = mylist.begin();
  ++myiterator;
  
  myiterator = mylist.erase(myiterator);
  std::cout << "Removed middle node" << std::endl;
  mylist.print_list();
  
  mylist.insert(myiterator, "five");
  std::cout << "Inserted new middle node" << std::endl;
  mylist.print_list();
  
  
  mylist.push_back("one");
  mylist.push_back("two");
  mylist.push_back("three");


  mylist.print_list();

  DoublyLinkedList<std::string>::iterator myiterator = mylist.end();

  myiterator = mylist.erase(myiterator);
  std::cout << "Removed tail node" << std::endl;
  mylist.print_list();
  
  mylist.insert(myiterator, "four");
  std::cout << "Inserted new tail node" << std::endl;
  mylist.print_list();
  
  myiterator = mylist.begin();
  ++myiterator;
  
  myiterator = mylist.erase(myiterator);
  std::cout << "Removed middle node" << std::endl;
  mylist.print_list();
  
  mylist.insert(myiterator, "five");
  std::cout << "Inserted new middle node" << std::endl;
  mylist.print_list();
  */
  return 0;
}