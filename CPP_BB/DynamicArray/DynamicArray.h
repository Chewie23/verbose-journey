#pragma once
#include <iostream>


template <typename T>
class DynamicArray {
protected:
    int size = 10; 
    int length = 0;
    int cur, count;
    T* dynArray;
public:
  
  DynamicArray() {
      dynArray = new T [size];
      cur = 0;
  }
  
  ~DynamicArray() {
      //delete[] dynArray;
  }

  
  T& operator[](int index) {
    return dynArray[index];
  }
  void push_back(const T& val) { //literally adds one on top of each other. Head will be be first in, last out.
      //Needs to expand if it hits 50% capacity
      if (cur == size/2) {
          int new_size = size * 2;
          T* temp = new T[new_size];
          for (int i = 0; i <= cur; ++i) {
              temp[i] = dynArray[i];
          }
          delete[] dynArray; //what I want is this to delete the OLD dynArray
          dynArray = temp; //Set up the new larger dynArray
          size = new_size;
      }
      
      dynArray[cur] = val;
      ++cur;
  }
  
  void pop_back() {
      /*if (cur == size/4) {
          int new_size = size / 2;
          T* temp = new T[new_size];
          for (int i = 0; i <= cur; ++i) {
              temp[i] = dynArray[i];
          }
          delete[] dynArray; //what I want is this to delete the OLD dynArray
          T* dynArray;
          dynArray = new T [new_size];
          dynArray = temp; //Set up the new larger dynArray
          size = new_size;
      }*/
      --cur;
    }

  const T* begin() const {
    return dynArray; //I want this to point to head of array. Not sure if this is right?
  }
  
  const T* end() const {
    return dynArray + (cur);
  }
};