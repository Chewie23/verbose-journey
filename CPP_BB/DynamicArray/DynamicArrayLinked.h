/*
General Idea

There are many useful container classes in the Standard Template Library (Links to an external site.). 
Each one can store objects with different trade-offs and benefits. 
The purpose of this assignment is to learn more about how templates and containers like std::vector (Links to an external site.).

Your job is to implement DynamicArray.h. You can add as much to it as you want, 
but make sure that you implement all of the functions that are already listed. 
Remember that since this is a template class, you must define each method in the header file instead of any .cpp file.

*/

//TODO: Make a linked list and implement it in a template.
//Linked List tutorial: http://pumpkinprogrammer.com/2014/06/13/c-tutorial-intro-to-linked-lists/
#pragma once
#include <iterator>

template <typename T>
class DynamicArray {
protected:
    struct node {
        T data; //T is the type name, or int in this case
        node* next;
        //node(T data, node* next) : data(data), next(next) {}
    };
    node* head; //initializes the head, current and tail node
    node* tail;
    node* cur;
    int listLength; //List length = 0. Will track how many nodes there are
public:
  DynamicArray() : head(nullptr), tail(nullptr), listLength(0) {}
  ~DynamicArray() {
    node *cur = head;
    while (head) {
        cur = head;
        head = head->next;
        delete cur;
    }
    head = NULL;
    tail = NULL;
  }
  T& operator[](int index) { //works
    int count = 0;
    cur = head;
    while (count != index) { //climbs through the linked list with our "cur" pointer
        cur = cur->next;
        count++; 
    }
    return cur->data;
  }
  void push_back(const T& val) {
    cur = new node(); 
    
    cur->data = val;
    
    cur->next = head;
    head = cur; //head points to new node, since we are adding to the beginning
    //std::cout << head->data << std::endl;
    listLength++;
    
    if(cur == NULL) {
        cur = head;
    }
    
  }

  void pop_back() { //deletes last element of container. Will not catch/handle if head = tail
  
    cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }
    //std::cout << cur->data << std::endl; //prints out the tail
    delete tail;
    tail = cur;
    tail->next = NULL;
  }

//HOW TO IMPLEMENT THIS??
  const T* begin() const { 
    //...
  }
  
  const T* end() const {
    //...
  }

};