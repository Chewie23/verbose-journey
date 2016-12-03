/*
Implement the Board and RobotPlayer classes. When Grade Oven is ready, 
you'll submit your tic_tac_toe.h and tic_tac_toe.cpp files to Grade Oven. 
Note that you won't be submitting a program, just the code for Board and Player. 
Furthermore, your RobotPlayer class should win against my RandomPlayer class, 
with makes completely random (but valid) moves.
*/
#include "RobotPlayer.h"

const char RobotPlayer::EMPTY = ' ';

bool RobotPlayer::is_board_empty(AbstractBoard* board) {
    int pieces_on_board = 0;
    for (int i = 0; i < 3; ++i) {
        for (int n = 0; n < 3; ++n) {
            if (!board->is_valid_move(i, n)) {
                ++pieces_on_board;
            }
        }
    }
    if (pieces_on_board != 0) {
        return false;
    }
    return true;   
};

void RobotPlayer::smart_move(AbstractBoard* board) {
    
    if (board->get_cell(1, 1) == RobotPlayer::EMPTY) {
        board->make_move(1, 1);
        move_vec.push_back(1);
    }
    
    else if (board->get_cell(0, 0) == RobotPlayer::EMPTY) { //Aiming for upper left
        board->make_move(0, 0);
        move_vec.push_back(1);
    }
    else if (board->get_cell (0, 2) == RobotPlayer::EMPTY) { // Upper right
        board->make_move(0, 2);
        move_vec.push_back(1);
    }
    else if (board->get_cell (2, 0) == RobotPlayer::EMPTY) { // Lower left
        board->make_move(2, 0);
        move_vec.push_back(1);
    }
    else if (board->get_cell (2, 2) == RobotPlayer::EMPTY) { //Lower right
        board->make_move(2, 2);
        move_vec.push_back(1);
    }

}

 
void RobotPlayer::make_move(AbstractBoard* board) { 
    
    //TODO: STEP 1. Check board is empty. HOW? For loop? Return false if NOT empty?
        if (is_board_empty(board)) {
            board->make_move(1, 1);//Aiming for center   
            move_vec.push_back(1);
        }
        else if (!is_board_empty(board) && move_vec.empty()) {
            smart_move(board);   
        }
        
        else if ((board->winner() != player)) {
            smart_move(board);
        }
        else {
            std::cout << "winner is " << board->winner() << std::endl;  
        }
    };
