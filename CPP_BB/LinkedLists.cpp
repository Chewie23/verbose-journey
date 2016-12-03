#include <iostream>

using namespace std;

// This is a very simple linked-list class.  A real linked list class would keep
// track of where it's head/beginning node was and have lots of useful methods.
class LinkedListNode {
public:
  int value;
  LinkedListNode *next;

  class iterator {
  public:
    LinkedListNode* cur;
    iterator(LinkedListNode* cur) : cur(cur) {}
    int& operator*() {  // *myiterator
      return cur->value;
    }
    iterator& operator++() {  // ++myiterator
      cur = cur->next;
      return *this;
    }
    bool operator!=(const iterator& rhs) {  // myiterator != rhs
      return (cur != rhs.cur);
    }
  };
  LinkedListNode(int x) : value(x) {}
  iterator begin() {
    // This iterator represents the "head" or begin position
    return iterator(this);
  }
  iterator end() {
    // This iterator represents just past the end of the LinkedList
    return iterator(nullptr);
  }
};

int main() {
  LinkedListNode *linked_list = new LinkedListNode(2);
  linked_list->next = new LinkedListNode(3);
  linked_list->next->next = new LinkedListNode(5);
  linked_list->next->next->next = nullptr;

  for (const int x : *linked_list) {
    cout << x << endl;
  }
  return 0;
}