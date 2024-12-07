#include <iostream>
using namespace std;

char board[3][3];  // 3x3 board
char player = 'X'; // Player X starts first

void initializeBoard() {
    // Fill board with numbers 1-9
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void printBoard() {
    // Display current board state
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
}

bool isCellEmpty(int choice) {
    // Check if the selected cell is empty
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int choice) {
    // Update board based on player's move
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = player;
}

bool checkWin() {
    // Check rows, columns, and diagonals for a winning condition
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    
    return false;
}

bool checkDraw() {
    // Check if all cells are filled without a winner
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void togglePlayer() {
    // Switch between players
    player = (player == 'X') ? 'O' : 'X';
}

int main() {
    int choice;
    initializeBoard();

    while (true) {
        cout << "Player " << player << "'s turn:\n";
        printBoard();
        
        cout << "Enter a number (1-9) to make a move: ";
        cin >> choice;

        if (choice < 1 || choice > 9 || !isCellEmpty(choice)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        makeMove(choice);

        if (checkWin()) {
            printBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (checkDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        togglePlayer();
    }

    return 0;
}

