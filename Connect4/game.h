#pragma once
#include "board.h"

class Game {
  public:
  Game();
  void play();
  private:
  Board board;
  int current_player;
  bool game_over;
};