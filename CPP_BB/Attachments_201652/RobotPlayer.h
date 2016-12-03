#pragma once

#include "AbstractPlayer.h"

class RobotPlayer : public AbstractPlayer {
 protected:
  // ...
 public:
  RobotPlayer(const char player) : AbstractPlayer(player) {}
  void make_move(AbstractBoard* board);
  // ...
};
