#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <initializer_list>
#include <iostream>

template <typename T>
struct DoublyLinkedListNode { //need to store the next, prev pointers in this node class
    DoublyLinkedListNode *next, *prev;
    T value;
    
    DoublyLinkedListNode(T value)
    : next(nullptr), prev(nullptr), value(value) {}
};


template <typename T>
class DoublyLinkedList {
    DoublyLinkedListNode <T> *head, *tail;
    int size_;
public:
    class iterator {
        DoublyLinkedListNode <T> *cur;
        bool reversed;
    public:
        iterator(DoublyLinkedListNode <T> *cur, bool reversed = false) 
        : cur(cur), reversed(reversed) {}
        iterator& operator--(){
            if (reversed) {
                cur = cur->next;
            } else {
                cur = cur->prev;
            }
            return *this;
        }
        iterator& operator++() {
            if (reversed) {
                cur = cur->prev;
            } else {
                cur = cur->next;
            }
            return *this;
        }
        const T& operator*() const {
            return cur->value;
        }
        bool operator!=(const iterator& other) const {
            return cur != other.cur;
        }
        // This allows DoublyLinkedList to be able to look at/modify anything in
        // iterator, even if it's in the private section.
        friend class DoublyLinkedList;
        };
    DoublyLinkedList(int size_ = 0)
    : head(nullptr), tail(nullptr), size_(size_) {};
    
    DoublyLinkedList(const DoublyLinkedList& other) : DoublyLinkedList(){
        for (const T& val: other) {
            push_back(val);
        }    
    }
     DoublyLinkedList(std::initializer_list<T> other_list): DoublyLinkedList() { //is this the reason why everything goes haywire with head() pointers?
        for (const auto& n: other_list) {
            push_back(n);
        }
    }
    ~DoublyLinkedList(){ //This may be the reason for all those segFaults in GradeOven. 
        DoublyLinkedListNode <T> *cur = head;
        while(cur != nullptr) {
            DoublyLinkedListNode <T> *to_delete = cur;
            cur = cur->next;
            delete to_delete;
        }
        head = nullptr;
        tail = nullptr;     
    }

    int size() const noexcept{
        return this->size_;
    }
    void push_back(const T& value){
        insert(end(), value);
    }
    
    void remove(const T& val) {
        iterator iter_end = end();
        for (iterator iter = this->begin(); iter != iter_end;) {
            if (*iter == val) {
                iter = erase(iter);
            } 
            else {
                ++iter;
            }    
        }          
    }
    //a little blunt and stupid but I need something blunt and stupid so I can figure out pointers 
    iterator erase(iterator position){ //fails GradeOven
         DoublyLinkedListNode <T> *marked_node = nullptr;
         DoublyLinkedListNode <T> *next_node = nullptr;
        if (!(position.cur != tail)) { //position == tail. This is more for remove(). How can I reconfigure remove() or this to be more...smooth
            marked_node = tail;
            next_node = nullptr;
            marked_node->prev->next = nullptr;
            tail = marked_node->prev;
            --size_;
        } else if (position.cur != nullptr) { //position != end()
            marked_node = position.cur;
            next_node = position.cur->next;
            if (marked_node != head) { //if position is in middle of head and tail
                marked_node->prev->next = marked_node->next;
                marked_node->next->prev = marked_node->prev; 
                --size_;
            } else if (!(marked_node->prev != nullptr)) { //position == begin()
                marked_node->next->prev = nullptr;
                this->head = marked_node->next; //if erasing head, need to re-point to next node
                --size_;
            }
        } else { //position == end()
            std::cout << "pos == end()" << std::endl;
            marked_node = tail;
            next_node = nullptr;
            marked_node->prev->next = nullptr;
            tail = marked_node->prev;
            --size_;
        }
        std::cout << "Marked_node: " << marked_node << "\t" << marked_node->value << std::endl;
        delete marked_node;
        if (next_node != nullptr) {
            position.cur = next_node;   
        }
        
        return position;
    }
    iterator insert(iterator position, const T& value) { //fails GradeOven
        DoublyLinkedListNode <T> *new_node = nullptr;
        if (new_node != nullptr) {
            std::cout << "New_Node initial: " << new_node << "\t" << new_node->value << std::endl;
        }
        new_node = new DoublyLinkedListNode <T> (value); 
        std::cout << "New_Node initial: " << new_node << "\t" << new_node->value << std::endl;
        if (position.cur != nullptr) { //position != end()
            if (position.cur->prev != nullptr) { //position != begin() 
                position.cur->prev->next = new_node; //insert in between two nodes
                new_node->prev = position.cur->prev;
                new_node->next = position.cur;
                position.cur->prev = new_node;
                ++size_;
            } else { //it is begin()
                new_node->prev = nullptr;
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
                ++size_;
            }
        } else if (size_ >= 1) {//position == end() and not empty
            //this causes the weird behavior with initializer_list and inserting
            std::cout << "\n===========Printing list from inside insert()===========" << std::endl;
            print_list();
            std::cout << "Looking at ends" << std::endl;
            print_ends();
            new_node->prev = tail; 
            tail->next = new_node; //updating the tail->next pointer
            new_node->next = nullptr;            
            tail = new_node;                 //update tail pointer to new_node
            ++size_;
            
        } else { //make node into first node
            std::cout << "Making first node" << std::endl;
            head = new_node;
            tail = new_node;
            std::cout << "Looking at ends" << std::endl;
            //print_ends();
            new_node->next = nullptr;
            new_node->prev = nullptr;
            ++size_;
        }
        return position;
    }

    void print_list() {
        std::cout << "\nPrinting list: " << std::endl;
        for (iterator pos = head; pos != end(); ++pos) {
            DoublyLinkedListNode <T> *cur_node = pos.cur;
            std::cout << *pos  << "\t" << (pos.cur) << std::endl;
            /*
            if (cur_node->next != nullptr) {
                std::cout << "The 'next' pointer is looking at: " <<cur_node->next->value << std::endl;
            }
            if (cur_node->prev != nullptr) {
                std::cout << "The 'prev' pointer is looking at: " << cur_node->prev->value << std::endl;
            }
            print_ends();
            */
        }
        std::cout << "Size of list is: " << size() << std::endl;
    }
    
    void rprint_list() { 
        std::cout << "entering rprint_list" << std::endl;
        for (iterator cur = rbegin(); cur != rend(); ++cur){
            std::cout << *cur  << std::endl;  
        }
    }
    
    void print_ends() {
        iterator curH = head;
        iterator curT = tail;
        std::cout << "The 'head' pointer is looking at: " << head->value << "\t" << head << std::endl;
        std::cout << "The 'tail' pointer is looking at: "<< tail->value << "\t" << tail << std::endl;
    }
    
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(nullptr);
    }
    iterator rbegin() {
        return iterator(tail, true);
    }
    iterator rend() {
        return iterator(nullptr, true);
    }
};

#endif  // _DOUBLY_LINKED_LIST_H_