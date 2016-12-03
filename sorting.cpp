#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

template<typename T>
std::vector<T> get_left_half(int mid, std::vector<T> container){ 
    std::vector<T> left_half;
    for (int i = 0; i < mid; ++i){
        left_half.push_back(container[i]);
    }
    return left_half;
}


template<typename T>    
std::vector<T> get_right_half(int mid, std::vector<T> container){
    std::vector<T> right_half;
    for (uint i = mid; i < container.size(); ++i){
        right_half.push_back(container[i]);
    }
    return right_half;
}

template<typename T>
void merge (std::vector<T>& container, std::vector<T>& left_half, std::vector<T>& right_half){
    uint i = 0, j = 0, k = 0;
        
    while (i < left_half.size() && j < right_half.size()){
        if(left_half[i] < right_half[j]){
            container[k] = left_half[i];
            ++i;
        } else {
            container[k] = right_half[j];
            ++j;
        }
        ++k;
    }
    
    while (i < left_half.size()){
        container[k] = left_half[i];
        ++i;
        ++k;
    }
    
    while (j < right_half.size()){
        container[k] = right_half[j];
        ++j;
        ++k;
    }
}

template<typename T>
void sort(std::vector<T>& container){
    if (container.size() > 1){ //if it is one element in the sub_vector
        int mid = (container.size()) / 2;
        //std::cout << mid << std::endl;
        std::vector<T> left_half  = get_left_half(mid, container);
        std::vector<T> right_half = get_right_half(mid, container);
        
        sort(left_half); 
        sort(right_half); //infinitely recurses here. The problem seems to be when we reach sub-vector.size() = 2, it gets confused
        
        merge(container, left_half, right_half);
    }
}

template<typename T>
void print_inventory(std::vector<T>& container){
    for (const T& x : container){
        std::cout << x << std::endl;
    }
}

int main() {
    std::vector<std::string> tupperware;

    for (std::string line; getline(std::cin, line); ) {
        tupperware.push_back(line);
    }
    
    sort(tupperware); //Need a better way to implement this, rather than using an index

    print_inventory(tupperware);
    
    return 0;
}