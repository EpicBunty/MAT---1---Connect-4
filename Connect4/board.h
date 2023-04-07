#pragma once
#include "player.h"
#include <string>
using namespace std;

class Board {
private:
  static const int ROWS = 6;
  static const int COLS = 7;
  string board[ROWS][COLS];

public:
  Board();
  int getCols();
  void init_board();
  bool check_win(const string player);
  void display_board();
  bool make_move(int col, const string player);
  bool check_board_full();
};
