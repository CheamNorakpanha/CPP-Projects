#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using the Caesar cipher
string encrypt(string message, int shift) {
    string encryptedMessage = "";

    for (char& c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        encryptedMessage += c;
    }

    return encryptedMessage;
}

// Function to decrypt a message using the Caesar cipher
string decrypt(string message, int shift) {
    return encrypt(message, 26 - shift); // Decryption is just encryption with the opposite shift
}

int main() {
    int shift;
    string message;

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter a shift value: ";
    cin >> shift;

    // Encrypt the message
    string encryptedMessage = encrypt(message, shift);
    cout << "Encrypted message: " << encryptedMessage << endl;

    // Decrypt the message
    string decryptedMessage = decrypt(encryptedMessage, shift);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
