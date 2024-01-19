#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_board() {
    cout << "PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "___________\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "___________\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

void player_turn() {
    cout << endl;
    cout << "Player " << turn << " turn: ";
    cin >> choice;

    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
        player_turn();
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    }
    else {
        cout << "Box already filled! Please choose another!\n";
        player_turn();
    }
}

bool game_over() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main() {
    cout << "T I C K -- T A C -- T O E -- G A M E\n\n";
    cout << "FOR 2 PLAYERS\n";

    while (game_over()) {
        display_board();
        player_turn();
        game_over();
    }

    if (turn == 'O' && !draw)
        cout << "\nCongratulations! Player with 'X' has won the game\n";
    else if (turn == 'X' && !draw)
        cout << "\nCongratulations! Player with 'O' has won the game\n";
    else
        cout << "\nGAME DRAW!!!\n";

    return 0;
}
