#include <iostream>
#include <vector>

template <typename T>
class Example {
protected:
    struct node {
        T data; //T is the type name, or int in this case
        node* next;
    }
    node* head; //initializes the head?
    int listLength; //List length = 0. Will track how many nodes there are

public:
    Example(){
        head->next = NULL; //Next node is NULL!
        listLength = T(); //T() = 0
    } 
    void SetData (T nData) {
        data = nData;
    }
    void PrintData() {
        std::cout << data << std::endl;
    }
};

int main () {
    Example<int> num[5];
    num.SetData(4);
    //num.PrintData();
}