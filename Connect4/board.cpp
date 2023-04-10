#include "board.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board() { init_board(); };

int Board::getCols() {
    return COLS;
}

void Board::init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = " ";
        }
    }
}

void Board::display_board() {
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

bool Board::make_move(int col, const string player) {
    if (board[0][col] != " ") { // check if empty
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

bool Board::check_board_full() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == " ") {
                return false;
            }
        }
    }
    return true;
}

bool Board::check_win(const string player) {
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
            if (i < ROWS - 3 && j < COLS - 3 && board[i][j] == player &&
                board[i + 1][j + 1] == player && board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player) {
                return true; // diagonal (top-left to bottom-right)
            }
            if (i < ROWS - 3 && j >= 3 && board[i][j] == player &&
                board[i + 1][j - 1] == player && board[i + 2][j - 2] == player &&
                board[i + 3][j - 3] == player) {
                return true; // diagonal (bottom-left to top-right)
            }
        }
    }
    return false;
}

;