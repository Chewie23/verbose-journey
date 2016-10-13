#include <iostream>
#include "ternary_search.h"

int main() {
    int arr[] = {-6, 0, 2, 36, 49, 53, 56, 67, 78, 84};
    
    std::cout << ternary_search(arr, 34, 0, 10) << std::endl;
}
