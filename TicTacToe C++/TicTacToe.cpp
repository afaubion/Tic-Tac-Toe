#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<char>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "|" << endl;
            cout << "-------------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
        
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') {
            return false; // Found an empty cell, not a draw
        }
    }
    return true; // No empty cells, it's a draw
}

int main() {
    vector<char> board(9, ' '); // Initialize a 9-element vector with spaces
    char currentPlayer = 'X';
    int move;

    cout << "Welcome to Tic Tac Toe!" << endl;

    do {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Validate the move
        if (move >= 1 && move <= 9 && board[move - 1] == ' ') {
            board[move - 1] = currentPlayer;

            // Check for win
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for draw
            if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Please try again." << endl;
        }

    } while (true);

    return 0;
}