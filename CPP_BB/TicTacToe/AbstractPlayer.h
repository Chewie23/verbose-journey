#pragma once

#include "AbstractBoard.h"

class AbstractPlayer {
 protected:
  const char player;  // either 'X' or 'O'
 public:
  AbstractPlayer(const char player) : player(player) {};
  // Take a board and make a move!
  virtual void make_move(AbstractBoard* board) = 0;
};
