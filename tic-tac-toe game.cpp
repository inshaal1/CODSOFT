#include <iostream>
using namespace std;
void displayboard();
void playerturn();
bool gameover();

char board[3][3] = { {'1','2','3','4','5','6','7','8','9'} };
int choice, row, column;
char turn = 'X';
bool game_draw = false;

int main() {
    cout << "tick tac toe game\n\n";
    while (gameover()) {
        displayboard();
        playerturn();
        gameover();
    }
    if (turn == 'O' && !draw)
        cout << "\ncongrats! player with 'X' has won the game\n";
    else if (turn == 'X' && !draw)
        cout << "\ncongrats! player with 'O' has won the game\n";
    else
        cout << "\n game ends in a draw \n";
    return 0;
}
void playerturn() {
    cout << endl;
    cout << "player " << turn << " turn: ";
    cin >> choice;
    switch (choice) {
    case 1: 
        row = 0;
        column = 0;
        break;
    case 2: 
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1; 
        column = 0;
        break;
    case 5: 
        row = 1;
        column = 1; 
        break;
    case 6:
        row = 1;
        column = 2; 
        break;
    case 7:
        row = 2; 
        column = 0; 
        break;
    case 8:
        row = 2;
        column = 1; 
        break;
    case 9:
        row = 2;
        column = 2; 
        break;
    default:
        cout << "invalid move";
        playerturn();
    }
    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    }
    else {
        cout << "the box is filled! please choose another!\n";
        playerturn();
    }
}
void displayboard() {
    cout << "PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
   << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n" << "___________\n"
   << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n"  << "___________\n"
   << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}
bool gameover() {
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])  { 
        return false;
    }
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
        }
    }
    game_draw = true;
    return false;
}
