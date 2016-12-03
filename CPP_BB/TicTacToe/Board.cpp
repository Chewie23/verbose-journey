//TODO
/*
- Make player take turns
- Make AI smarter than rando AI

*/
#include "Board.h"

const char Board::EMPTY = ' ';

Board::Board() {//This is a constructor for Board, create the 2D array here
    Board::reset();
    player = 'X';
}

char Board::get_cell(int x, int y) const {
    return grid[x][y];
}

bool Board::make_move(int x, int y) { //Need to have robot player check if move is going to be valid, thus while loop!
    if (is_valid_move(x, y)) { //Only runs if valid move is false! Need to flip player and mark correctly
        grid[x][y] = player; 
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
        return true;
    }
    return false;
}

bool Board::undo_last_move() { //will check if move made is valid/true. if not, undo and returns false.
  // I actually don't know why we need this?
}

char Board::current_player() const {
    return player;
}

char Board::winner() const { //YAYYYY. Works
  char piece;
    for (int row = 0; row < 3; ++row) {
        piece = get_cell(row, 0);
        if(piece != Board::EMPTY && get_cell(row, 1) == piece && get_cell(row, 2) == piece){
            return piece; // Checks row match 
        }
    }
    for (int col = 0; col < 3; ++col) {
        piece = get_cell(0, col);
        if(piece != Board::EMPTY && get_cell(1, col) == piece && get_cell(2, col) == piece){
            return piece; // Checks col match
        }
    }
    // Below Checks diagonal matches.
    piece = get_cell(0, 0);
    if(piece != Board::EMPTY && get_cell(1, 1) == piece && get_cell(2, 2) == piece){
        return piece; 
    }
    piece = get_cell(0, 2);
    if(piece != Board::EMPTY && get_cell(1, 1) == piece && get_cell(2, 0) == piece){
        return piece;
    };
}


void Board::reset() {
    for (int i = 0; i < 3; ++i) {
        for (int n = 0; n < 3; ++n) {
            grid[i][n] = Board::EMPTY; //initializes empty board.
        }
    }
}
