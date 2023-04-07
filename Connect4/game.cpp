#include "game.h"
#include <iostream>

Game::Game(){};

void Game::play() {
  int player_index = 0;
  Player player1(RED_PLAYER, RED_TOKEN);
  Player player2(BLUE_PLAYER, BLUE_TOKEN);
  Player player[2] = {player1, player2};
  game_over = false;
  board.display_board();
  string input;
  while (!game_over) {
    int col;
    cout << "\n\nPlayer " << player[player_index].getName() << ", enter column: ";
    // Read in input as string
    getline(cin, input);

    try {
      // Attempt to convert input to integer
      col = stoi(input);
    } catch (invalid_argument e) {

      // Conversion failed, input was not a valid integer
      cout << "\n\nInvalid input. Try again." << endl;
      continue;
    }

    col--;
    // Convert column number to 0-based index
    if (col < 0 || col >= board.getCols()) {
      cout << "\n\nInvalid column. Please enter a column between 1 and 7." <<endl;
      continue;
    }

    if (!board.make_move(col, player[player_index].getToken())) {
      cout << "\n\nColumn is full. Please choose a different column." << endl;
      continue;
    }

    if (board.check_win(player[player_index].getToken())) {
      board.display_board();
      cout << "\n\nPlayer " << player[player_index].getName() << " wins!" << endl;
      game_over = true;

    } else if (board.check_board_full()) {
      cout << "\n\nBoard is full. Game draw." << endl;
      game_over = true;

    } else {
      board.display_board();
      player_index = (player_index + 1) % 2;
    }
  }
};