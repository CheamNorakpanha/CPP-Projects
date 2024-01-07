#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store user information
struct User {
    string username;
    string password;
};

// Function to register a new user
void registerUser() {
    User newUser;
    
    cout << "Enter a username: ";
    cin >> newUser.username;

    cout << "Enter a password: ";
    cin >> newUser.password;

    // Open the database file in append mode
    ofstream database("users.txt", ios::app);

    // Check if the file is open
    if (database.is_open()) {
        // Write the user information to the file
        database << newUser.username << " " << newUser.password << endl;
        database.close();

        cout << "Registration successful!" << endl;
    } else {
        cout << "Error opening the database file." << endl;
    }
}

// Function to check if a user exists in the database
bool userExists(const string& username, const string& password) {
    ifstream database("users.txt");

    // Check if the file is open
    if (!database.is_open()) {
        cout << "Error opening the database file." << endl;
        return false;
    }

    // Read the file line by line
    string line;
    while (getline(database, line)) {
        size_t pos = line.find(' ');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);

        // Check if the provided credentials match any entry in the file
        if (username == storedUsername && password == storedPassword) {
            database.close();
            return true; // User exists
        }
    }

    database.close();
    return false; // User does not exist
}

// Function for user login
void loginUser() {
    User loginUser;

    cout << "Enter your username: ";
    cin >> loginUser.username;

    cout << "Enter your password: ";
    cin >> loginUser.password;

    if (userExists(loginUser.username, loginUser.password)) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 3);

    return 0;
}
