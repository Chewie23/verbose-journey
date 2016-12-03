#pragma once

#include "AbstractPlayer.h"
#include <vector>

class RobotPlayer : public AbstractPlayer {
 protected:
  std::vector< int > move_vec; //keeps track of moves
 public:
  RobotPlayer(const char player) : AbstractPlayer(player) {} //In AbstractPlayer.h
  static const char EMPTY;
  void make_move(AbstractBoard* board);
  void smart_move(AbstractBoard* board);
  bool is_board_empty(AbstractBoard* board);
};
