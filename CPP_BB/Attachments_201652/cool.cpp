#include <iostream>
#include "Board.h"

int test_move(Board practice, int x, int y) {
    practice.make_move(x, y);
    return 0;
}

int main() {
    Board practice;

    practice.make_move(0, 2);
    practice.make_move(1, 2);
    practice.make_move(1, 1);
    practice.make_move(2, 1);
    practice.make_move(2, 0); 
    
    std::cout << practice << std::endl;
    std::cout << practice.winner() << std::endl;
    
    //practice.reset();
    //std::cout << practice.get_cell(1, 0) << std::endl;
    //std::cout << practice.get_cell(0, 2) << std::endl;
    //practice.make_move(1, 2); //This needs to fail.
    
    //practice.print_board();
    return 0;
}


