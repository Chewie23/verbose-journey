#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>




/* Python version
def mergeSort(alist):
    print("Splitting ",alist)
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
    print("Merging ",alist)

OUTPUT:
Splitting  [54, 26, 93, 17, 77, 31, 44, 55, 20]
Splitting  [54, 26, 93, 17]
Splitting  [54, 26]
Splitting  [54]
Merging  [54]
Splitting  [26]
Merging  [26]
Merging  [26, 54]
Splitting  [93, 17]
Splitting  [93]
Merging  [93]
Splitting  [17]
Merging  [17]
Merging  [17, 93]
Merging  [17, 26, 54, 93]
Splitting  [77, 31, 44, 55, 20]
Splitting  [77, 31]
Splitting  [77]
Merging  [77]
Splitting  [31]
Merging  [31]
Merging  [31, 77]
Splitting  [44, 55, 20]
Splitting  [44]
Merging  [44]
Splitting  [55, 20]
Splitting  [55]
Merging  [55]
Splitting  [20]
Merging  [20]
Merging  [20, 55]
Merging  [20, 44, 55]
Merging  [20, 31, 44, 55, 77]
Merging  [17, 20, 26, 31, 44, 54, 55, 77, 93]
[17, 20, 26, 31, 44, 54, 55, 77, 93]
*/


//MAY want to redo this as a function
template <typename T>
class Container{
public:
    
    std::vector<T> container;
    
    void insert(const T& str){
        container.push_back(str);
    }
    
    
    //BUG
    //recurses infinitely.
    //Error in splitting the vector in half. I need a way to account for even size. Right now, odd size is okay.
    
    std::vector<T> get_left_half(int mid){ 
        std::vector<T> left_half;
        for (int i = 0; i < mid; ++i){
            std::cout << "left_half Index: " << i << std::endl;
            left_half.push_back(container[i]);
        }
        return left_half;
    }
    
    std::vector<T> get_right_half(int mid){
        std::vector<T> right_half;
        for (uint i = mid; i < container.size(); ++i){
            std::cout << "right_half Index: " << i - (mid) << std::endl;
            right_half.push_back(container[i]);
        }
        return right_half;
    }
    
    
    void sort(std::vector<T>& container){
        if (container.size() > 1){ //if it is one element in the sub_vector
            int mid = (container.size()) / 2;
            //std::cout << mid << std::endl;
            std::vector<T> left_half  = get_left_half(mid);
            for (const T& x : left_half){
                std::cout << x << std::endl;
            }
            std::vector<T> right_half = get_right_half(mid);
            for (const T& x : right_half){
                std::cout << x << std::endl;
            }
            
            
            std::cout << right_half.size() << std::endl;
            
            //sort(left_half); 
           
            //sort(right_half); //infinitely recurses here. The problem seems to be when we reach sub-vector.size() = 2, it gets confused
            /*
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
            
            for (const T& x : container){
                std::cout << "Currently in container: " << x << std::endl;
            }*/
        }
    }
};
