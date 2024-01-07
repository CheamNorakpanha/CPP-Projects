#include <iostream>
#include <string>
#include <vector>

using namespace std;


class HangmanFigure {
public:
    void draw(int incorrectGuesses) const {
        switch (incorrectGuesses) {
            case 0:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "       |\n";
                cout << "       |\n";
                cout << "       |\n";
                cout << "       |\n";
                break;
            case 1:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "   O   |\n";
                cout << "       |\n";
                cout << "       |\n";
                cout << "       |\n";
                break;
            case 2:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "   O   |\n";
                cout << "   |   |\n";
                cout << "       |\n";
                cout << "       |\n";
                break;
            case 3:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "   O   |\n";
                cout << "  /|   |\n";
                cout << "       |\n";
                cout << "       |\n";
                break;
            case 4:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "   O   |\n";
                cout << "  /|\\  |\n";
                cout << "       |\n";
                cout << "       |\n";
                break;
            case 5:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "   O   |\n";
                cout << "  /|\\  |\n";
                cout << "  /    |\n";
                cout << "       |\n";
                break;
            case 6:
                cout << "   _____\n";
                cout << "   |   |\n";
                cout << "   O   |\n";
                cout << "  /|\\  |\n";
                cout << "  / \\  |\n";
                cout << "       |\n";
                break;
        }
    }
};

class Word {
private:
    string secretWord;
    string guessedWord;

public:
    Word(const string& word) : secretWord(word) {
        guessedWord = string(secretWord.length(), '_');
    }

    bool guess(char letter) {
        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                guessedWord[i] = letter;
                correctGuess = true;
            }
        }
        return correctGuess;
    }

    bool isWordGuessed() const {
        return secretWord == guessedWord;
    }

    string getGuessedWord() const {
        return guessedWord;
    }
};

class Hangman {
private:
    Word word;
    HangmanFigure hangmanFigure;
    int maxIncorrectGuesses;
    int incorrectGuesses;

public:
    Hangman(const string& secretWord, int maxIncorrect) : word(secretWord), maxIncorrectGuesses(maxIncorrect), incorrectGuesses(0) {}

    void play() {
        while (incorrectGuesses < maxIncorrectGuesses && !word.isWordGuessed()) {
            displayHangman();
            displayWordProgress();

            char guess;
            cout << "Enter a letter: ";
            cin >> guess;

            if (!isGuessValid(guess)) {
                cout << "Invalid guess. Please enter a letter.\n";
                continue;
            }

            if (word.guess(guess)) {
                cout << "Correct guess!\n";
            } else {
                cout << "Incorrect guess.\n";
                incorrectGuesses++;
            }
        }

        displayHangman();
        displayWordProgress();

if (word.isWordGuessed()) {
            cout << "Congratulations! You guessed the word.\n";
        } else {
            cout << "Sorry, you ran out of guesses. The word was: " << word.getGuessedWord() << "\n";
        }
    }

private:
    void displayHangman() const {
        hangmanFigure.draw(incorrectGuesses);
    }

    void displayWordProgress() const {
        cout << "Word: " << word.getGuessedWord() << "\n";
    }

    bool isGuessValid(char guess) const {
        return isalpha(guess);
    }
};

int main() {
    string secretWord;
    int maxIncorrectGuesses;

    cout << "Enter the secret word: ";
    cin >> secretWord;

    cout << "Enter the maximum number of incorrect guesses: ";
    cin >> maxIncorrectGuesses;

    Hangman hangmanGame(secretWord, maxIncorrectGuesses);
    hangmanGame.play();

    return 0;
}