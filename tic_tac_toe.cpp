#include <iostream>
#include <vector>

using namespace std;

// Game board
vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Function to display the game board
void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to handle player input
void playerInput(char player) {
    int move;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "Invalid move, try again.\n";
        playerInput(player);
    }
}

// Function to check for win
bool checkForWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check for draw
bool checkForDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        displayBoard();
        playerInput(currentPlayer);

        if (checkForWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkForDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Play again? (y/n): ";
    char response;
    cin >> response;

    if (response == 'y') {
        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        main();
    }

    return 0;
}