/*
This class just has to correctly implement all of the AbstractBoard methods 
according to the comment descriptions. If something is unclear, 
post a Discussion on Canvas.
*/


#pragma once

#include "AbstractBoard.h"

class Board : public AbstractBoard {
 protected:
  char grid[3][3]; // Protected, so only child classes can change it/access it
  char player;
 public:
  Board();
  static const char EMPTY; //Set in Board.cpp
  char get_cell(int x, int y) const;
  bool make_move(int x, int y);
  bool undo_last_move();
  char current_player() const;
  char winner() const;
  void reset();
  // ...
};
