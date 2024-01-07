#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10; // Change this value to adjust the size of the Minesweeper grid

class Minesweeper {
private:
    vector<vector<char>> board;
    vector<vector<bool>> revealed;
    vector<pair<int, int>> mines;
    int size;

public:
    Minesweeper(int gridSize) : size(gridSize) {
        board.resize(size, vector<char>(size, ' '));
        revealed.resize(size, vector<bool>(size, false));
        placeMines();
        calculateNumbers();
    }

    void displayBoard() {
        cout << "   ";
        for (int i = 0; i < size; ++i) {
            cout << " " << i;
        }
        cout << endl;

        for (int i = 0; i < size; ++i) {
            cout << " " << i << " |";
            for (int j = 0; j < size; ++j) {
                if (revealed[i][j]) {
                    cout << " " << board[i][j];
                } else {
                    cout << " -";
                }
            }
            cout << endl;
        }
    }

    void play() {
        while (true) {
            displayBoard();
            int row, col;
            cout << "=> Enter row and column (separated by space): ";
            cin >> row >> col;  

            if (!isValidInput(row, col)) {
                cout << "Invalid input. Try again." << endl;
                continue;
            }

            if (isMine(row, col)) {
                cout << "\nGame over! You hit a mine." << endl;
                revealAll();
                displayBoard();
                break;
            }

            if (isWon()) {
                cout << "Congratulations! You won!" << endl;
                revealAll();
                displayBoard();
                break;
            }

            revealCell(row, col);
        }
    }

private:
    void placeMines() {
        srand(time(0));
        int minesToPlace = size * size / 5; // Adjust the density of mines by changing the divisor

        while (minesToPlace > 0) {
            int row = rand() % size;
            int col = rand() % size;

            if (board[row][col] != '*') {
                board[row][col] = '*';
                mines.push_back({row, col});
                minesToPlace--;
            }
        }
    }

    void calculateNumbers() {
        for (const auto& mine : mines) {
            int row = mine.first;
            int col = mine.second;

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int newRow = row + i;
                    int newCol = col + j;

                    if (isValidCell(newRow, newCol) && board[newRow][newCol] != '*') {
                        board[newRow][newCol]++;
                    }
                }
            }
        }
    }

    void revealCell(int row, int col) {
        if (!isValidCell(row, col) || revealed[row][col]) {
            return;
        }

        revealed[row][col] = true;

        if (board[row][col] == ' ') {
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    revealCell(row + i, col + j);
                }
            }
        }
    }

    void revealAll() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                revealed[i][j] = true;
            }
        }
    }

    bool isValidCell(int row, int col) {
        return row >= 0 && row < size && col >= 0 && col < size;
    }

    bool isValidInput(int row, int col) {
        return cin.good() && row >= 0 && row < size && col >= 0 && col < size;
    }

    bool isMine(int row, int col) {
        return board[row][col] == '*';
    }

    bool isWon() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!revealed[i][j] && board[i][j] != '*') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Minesweeper game(SIZE);
    game.play();

    return 0;
}