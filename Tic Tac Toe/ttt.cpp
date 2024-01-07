#include <iostream>
using namespace std;

char square[11] = {'o', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

int checkwin();
void board();

int main() {
    int player = 1, choice;
    char mark;

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a letter (a to j): ";
        cin >> mark;

        choice = mark - 'a' + 1;

        if (choice >= 1 && choice <= 10 && square[choice] == mark) {
            square[choice] = (player == 1) ? 'X' : 'O';
        } else {
            cout << "Invalid move ";
            cin.ignore();
            cin.get();
            continue;
        }

        player++;

    } while (checkwin() == -1);

    board();

    if (checkwin() == 1) {
        cout << "==> \aPlayer " << (player == 1 ? 'X' : 'O') << " wins!";
    } else {
        cout << "==> \aGame draw";
    }

    cin.ignore();
    cin.get();
    return 0;
}

int checkwin() {
    for (int i = 1; i <= 10; i += 3) {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2]) {
            return 1;  // Row win
        }
    }

    for (int i = 1; i <= 4; ++i) {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6]) {
            return 1;  // Column win
        }
    }

    if (square[1] == square[5] && square[5] == square[9]) {
        return 1;  // Diagonal win
    }

    if (square[3] == square[5] && square[5] == square[7]) {
        return 1;  // Diagonal win
    }

    for (int i = 1; i <= 10; ++i) {
        if (square[i] == 'a' + i - 1) {
            return -1;  // Game in progress
        }
    }

    return 0;  // Draw
}

void board() {
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}