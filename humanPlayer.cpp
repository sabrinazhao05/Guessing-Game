#include "humanPlayer.h"

HumanPlayer::HumanPlayer() : Player() {}

HumanPlayer::HumanPlayer(const std::string& playerName) : Player(playerName) {}

int HumanPlayer::getGuess() const {
    int guess;
    do {
        std::cout << name << ", enter your guess (0-99): ";
        std::cin >> guess;
    } while (guess < 0 || guess > 99);
    return guess;
}
