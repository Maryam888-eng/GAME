#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char turn = 'X';
int row, col;
bool draw = false;

void displayBoard() {
    cout << "Player 1 [X]  -  Player 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "     |     |     \n\n";
}

bool checkWin() {
    // Rows and Columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void playerTurn() {
    int choice;
    if (turn == 'X') {
        cout << "Player 1 [X] turn: ";
    } else {
        cout << "Player 2 [O] turn: ";
    }
    cin >> choice;

    switch (choice) {
    case 1: row = 0; col = 0; break;
    case 2: row = 0; col = 1; break;
    case 3: row = 0; col = 2; break;
    case 4: row = 1; col = 0; break;
    case 5: row = 1; col = 1; break;
    case 6: row = 1; col = 2; break;
    case 7: row = 2; col = 0; break;
    case 8: row = 2; col = 1; break;
    case 9: row = 2; col = 2; break;
    default: cout << "Invalid choice!\n"; break;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Try again.\n";
        playerTurn();
    }
}

int main() {
    while (!checkWin() && !checkDraw()) {
        displayBoard();
        playerTurn();
    }

    displayBoard();

    if (checkWin()) {
        turn = (turn == 'X') ? 'O' : 'X';
        cout << "Congratulations! Player " << (turn == 'X' ? 1 : 2) << " wins!\n";
    } else if (checkDraw()) {
        cout << "It's a draw!\n";
    }

    return 0;
}
