#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';

void drawBoard() {
    for (int i = 0; i < 9; i += 3)
        cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n---|---|---\n";
}

bool checkWin() {
    for (int i = 0; i < 9; i += 3)
        if (board[i] == board[i+1] && board[i+1] == board[i+2]) return true;
    for (int i = 0; i < 3; ++i)
        if (board[i] == board[i+3] && board[i+3] == board[i+6]) return true;
    if (board[0] == board[4] && board[4] == board[8]) return true;
    if (board[2] == board[4] && board[4] == board[6]) return true;
    return false;
}

void playerMove() {
    int move;
    cout << "Enter position (1-9): "; cin >> move;
    if (board[move-1] == 'X' || board[move-1] == 'O') {
        cout << "Invalid move, try again.\n"; playerMove();
    } else board[move-1] = player;
}

void cpuMove() {
    for (int i = 0; i < 9; ++i)
        if (board[i] != 'X' && board[i] != 'O') {
            board[i] = 'O'; break;
        }
}

int main() {
    drawBoard();
    for (int i = 0; i < 9; ++i) {
        (player == 'X') ? playerMove() : cpuMove();
        drawBoard();
        if (checkWin()) { cout << player << " wins!\n"; break; }
        player = (player == 'X') ? 'O' : 'X';
    }
    if (!checkWin()) cout << "It's a tie!\n";
}
