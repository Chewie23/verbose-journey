#pragma once

#include <iostream>

class AbstractBoard {
 public:
  // Get the value at the cell
  // (0, 0) is the top-left and (1, 2) is the middle-bottom
  // this will return one of 'X', 'O', or ' '
  virtual char get_cell(int x, int y) const = 0;
  // Attempt to make a move.
  // Returns true if the move succeeded and false otherwise
  virtual bool make_move(int x, int y) = 0;
  // undo the last move and return true unless
  // the last move was already undone, then return false
  virtual bool undo_last_move() = 0;
  // Returns 'X' if it's X's turn, otherwise 'O'.
  virtual char current_player() const = 0;
  // Return 'X' if X has won, 'O' if O has won, and ' ' otherwise
  virtual char winner() const = 0;
  // You know what this does.  I believe in you.
  bool is_valid_move(int x, int y) const;
  // reset the board to it's initial state
  virtual void reset() = 0;

  // Prints the board, e.g.
  //  X| |O
  //  -+-+-
  //   |X|O
  //  -+-+-
  //   | |X
  friend std::ostream& operator<<(std::ostream& os, const AbstractBoard& board);
};
