#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int cardsLeft = 52;
    Card user;
    Card computer;
    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));

    //create decks
    Deck playing;
    Deck discard;

    playing.populate();
    playing.shuffle();

    play = true;
    while(play) {
        // assign values to computer and user
        //compValue = rand() % 52;
        //userValue = rand() % 52;
        computer = playing.pickCard();
        discard.addCard(computer);

        user = playing.pickCard();
        discard.addCard(user);

        playing.shuffle();

        // get user's bet
        cout << "Computer's value is ";
        cout << computer.CardPrint() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
            cardsLeft = cardsLeft - 2;
        }

        // determine outcome
        if((computer < user && guessedHigher) || (computer > user && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((computer > user && guessedHigher) || (computer < user && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tYour value is ";
        cout << user.CardPrint() << endl;
        discard.PrintDiscard();

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
        if(cardsLeft <= 0)
        {
            invalid = false;
            break;
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}