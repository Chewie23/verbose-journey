#include <iostream>

int main() {
    char name[] = {'J', 'e', 'n'};
    int x = 123;
    
    std::cout << name[-1] << std::endl; //undefined behavior. May be a seg fault, may not be. But definitely something funky is happening
    
    int *p = &x;
    std::cout << *p;
    }