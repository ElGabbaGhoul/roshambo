#include <cctype>
#include <iostream>
#include <random>

using namespace std;

const string moveChoice[3] = {"rock", "paper", "scissors"};

void displayInstructions() {
    cout << "Rock beats scissors, scissors beat paper, and paper beats rock."
         << endl;
    cout << "\nPick a move, the computer will then pick a move at random. ";
    cout << "\nThen one of you will be named the winner!\n" << endl;
}

int getMove() {
    string playerInput = "";
    int playerMove;
    bool valid = false;

    // validate input
    do {
        cout << "What is your move? R, P, S?" << endl;
        cin >> playerInput;
        if (!cin.fail()) {
            // Valid integer
            if (playerInput.length() >= 0) {
                for (char &c : playerInput) {
                    c = tolower(c);
                }
                playerInput = playerInput.substr(0, 1);
                if (playerInput == "r") {
                    playerMove = 0;
                    valid = true;
                } else if (playerInput == "p") {
                    playerMove = 1;
                    valid = true;
                } else if (playerInput == "s") {
                    playerMove = 2;
                    valid = true;
                }
            } else {
                cout << "Invalid input!" << endl;
            }
        } else {
            // invalid integer
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (!valid);

    return playerMove;
}

int getCompMove() {
    // Create a random number engine
    random_device rd;
    mt19937 gen(rd());

    // Generate number between 0 and 2
    uniform_int_distribution<> dis(0, 2);

    int computerMove = dis(gen);

    return computerMove;
}

// 0 = rock, 1 = paper, 2 = scissors
void getWinner(const int playerMove, const int computerMove) {
    if (playerMove == computerMove + 1) {
        cout << "Player: " << moveChoice[playerMove] << ", "
             << "Computer: " << moveChoice[computerMove] << ". \nPlayer wins!"
             << endl;
    } else if (playerMove == 0 && computerMove == 2) {
        cout << "Player: " << moveChoice[playerMove] << ", "
             << "Computer: " << moveChoice[computerMove] << ". \nPlayer wins!"
             << endl;
    } else if (playerMove != computerMove) {
        cout << "Player: " << moveChoice[playerMove] << ", "
             << "Computer: " << moveChoice[computerMove] << ". \nComputer wins!"
             << endl;
    } else {
        cout << "Player: " << moveChoice[playerMove] << ", "
             << "Computer: " << moveChoice[computerMove] << ". \nTie Game!" << endl;
    }
}

bool playAgain() {
    string response;
    bool replay = false;

    cout << "\nWould you like to play again? \nY/N" << endl;
    cin >> response;

    if (response == "y") {
        replay = true;
    } else if (response == "n") {
        cout << "Thanks for playing! Goodbye!" << endl;
        replay = false;
    } else {
        cout << "Please enter only y or n!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        replay = playAgain();
    }
    return replay;
}

int main() {
    displayInstructions();
    int playerMove = getMove();
    int computerMove = getCompMove();
    getWinner(playerMove, computerMove);
    if (playAgain() == true) {
        main();
    }

    return 0;
}
