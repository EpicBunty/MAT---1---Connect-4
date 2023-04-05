#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

const string RED_COLOR = "\033[1;31mO\033[0m";
const string BLUE_COLOR = "\033[1;34mO\033[0m";

const string RED_PLAYER = "\033[1;31m1\033[0m";
const string BLUE_PLAYER = "\033[1;34m2\033[0m";

string board[ROWS][COLS];

void init_board() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = " ";
    }
  }
}

void display_board() {
  system("clear");
  cout << " \n\n       C O N N E C T - 4\n\n\n";
  for (int i = 0; i < ROWS; i++) {
    cout << "----------------------------------------------";
    cout << "\n" << i + 1 << "  |  ";

    for (int j = 0; j < COLS; j++) {
      cout << board[i][j] << "  |  ";
    }

    cout << endl;
  }
  cout << "----------------------------------------------"
       << "\n   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |";
}

bool check_win(const string &player) {
  // Check horizontal and vertical
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (j < COLS - 3 && board[i][j] == player && board[i][j + 1] == player &&
          board[i][j + 2] == player && board[i][j + 3] == player) {
        return true; // horizontal
      }
      if (i < ROWS - 3 && board[i][j] == player && board[i + 1][j] == player &&
          board[i + 2][j] == player && board[i + 3][j] == player) {
        return true; // vertical
      }
      if (board[i][j] == player && board[i + 1][j + 1] == player &&

          board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
        return true;
      }
      if (board[i][j] == player && board[i + 1][j - 1] == player &&

          board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
        return true;
      }
    }
  }

  return false;
}

bool make_move(int col, const string &player) {
  if (board[0][col] != " ") {
    return false;
  }
  int row = -1;
  for (int i = ROWS - 1; i >= 0; i--) {
    if (board[i][col] == " ") {
      row = i;
      break;
    }
  }
  if (row == -1) {
    return false;
  }
  board[row][col] = player;
  return true;
}

bool check_board_full() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == " ") {
        return false;
      }
    }
  }
  return true;
}

string player_name(int index) {
  if (index == 0) {
    return RED_PLAYER;
  } else {
    return BLUE_PLAYER;}
}

int main() {
  init_board();

  string players[2] = {RED_COLOR, BLUE_COLOR};

  int player_index = 0;
  string input;
  display_board();
  bool game_over = false;
  while (!game_over) {

    int col;
    cout << "\n\nPlayer " << player_name(player_index) << ", enter column: ";
    // Read in input as string
    getline(cin, input);

    try {
      // Attempt to convert input to integer
      col = stoi(input);
    } catch (invalid_argument e) {

      // Conversion failed, input was not a valid integer
      cout << "Invalid input. Try again." << endl;
      continue;
    }

    col--;
    // Convert column number to 0-based index
    if (col < 0 || col >= COLS) {
      cout << "Invalid column. Please enter a column between 1 and 7." << endl;
      continue;
    }

    if (!make_move(col, players[player_index])) {
      cout << "Column is full. Please choose a different column." << endl;
      continue;
    }

    if (check_win(players[player_index])) {
      display_board();
      cout << "\n\nPlayer " << players[player_index] << " wins!" << endl;
      game_over = true;

    } else if (check_board_full()) {
      cout << "\n\nBoard is full. Game draw." << endl;
      game_over = true;

    } else {
      display_board();
      player_index = (player_index + 1) % 2;
    }
  }
}
