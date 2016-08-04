#include <iostream>

#include "AbstractBoard.h"

bool AbstractBoard::is_valid_move(int x, int y) const {
  return get_cell(x, y) == ' '; //Boolean check!
}

std::ostream& operator<<(std::ostream& os, const AbstractBoard& board) {
  for (int y = 0; y < 3; ++y) {
    os << board.get_cell(0, y) << '|'
       << board.get_cell(1, y) << '|'
       << board.get_cell(2, y) << '\n';
    if (y != 2) {
      os << "-+-+-\n";
    }
  }
  return os;
}
