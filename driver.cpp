//File name: driver.cpp
//Author: Sabrina Zhao
//Email: szhao74@fordham.edu
//Description: This code is a number guessing game where two players (either human or computer-controlled) take turns guessing a randomly generated number.
//The program allows for different configurations of players (0, 1, or 2 human players), and the game continues until one player correctly guesses the number. 
//After each round, the stats of both players are displayed, and the option to play again is provided. 
//qThe game involves classes for `Player`, `HumanPlayer`, and `ComputerPlayer`, which handle various aspects of player interactions, including making guesses and recording wins or losses.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"

using namespace std;

void play(Player& player1, Player& player2);
//Pre-condition: Both player1 and player2 must be initialized and ready to play.
//Post-condition: The state of both players may be updated based on the game's progress.

bool checkForWin(Player& player, int answer);
//Pre-condition: The player must be initialized and the answer must be a valid game input.
//Post-condition: Returns true if the player has met the winning condition, otherwise it is false.

void displayGameStats(const Player& player1, const Player& player2);
//Pre-condition: Both player1 and player2 must be initialized and contain valid game data.
//Post-condition: Outputs the game statistics without modifying the state of the players.

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Set the random seed

    int numPlayers;
    Player* p1 = nullptr;
    Player* p2 = nullptr;

    HumanPlayer h1("Player 1"), h2("Player 2");
    ComputerPlayer c1("CPU 1"), c2("CPU 2");
    
    cout << "How many human players? (0, 1, or 2): ";
    
    while (true) {
    cin >> numPlayers;

    if (cin.fail() || numPlayers < 0 || numPlayers > 2) {
        cin.clear();
        cin.ignore(10000, '\n'); 
        cout << "Please re-enter the number of players. (0, 1, or 2): ";
    } else {
        break;
    }
}

    if (numPlayers == 0) {
        p1 = &c1;
        p2 = &c2;
    } else if (numPlayers == 1) {
        p1 = &h1;
        p2 = &c2;
    } else {
        p1 = &h1;
        p2 = &h2;
        cout << "Enter name for Player 1: ";
        string name1;
        cin >> name1;
        h1.setName(name1);

        cout << "Enter name for Player 2: ";
        string name2;
        cin >> name2;
        h2.setName(name2);
    }
    
    char playAgain;
    do {
        play(*p1, *p2);
        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << endl;
    displayGameStats(*p1, *p2);

    return 0;
}

void play(Player& player1, Player& player2)
{
    int answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        win = checkForWin(player1, answer);
        if (win)
        {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win)
        {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

bool checkForWin(Player& player, int answer)
{
    bool win = false;
    cout << player.getName() << "'s turn to guess." << endl;
    int guess = player.getGuess();
    cout << "You guessed " << guess << ". ";
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        win = true;
    }
    else
        player.wrongGuess(guess, answer);
    return win;
}

void displayGameStats(const Player& player1, const Player& player2) {
    cout << "Final Results:" << endl;
    cout << player1 << endl;
    cout << player2 << endl;

    if (player1 > player2) {
        cout << "Congratulations, " << player1.getName() << "!" << endl;
    } else if (player2 > player1) {
        cout << "Congratulations, " << player2.getName() << "!" << endl;
    } else {
        cout << "We have a tie!" << endl;
    }
}