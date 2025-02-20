#include "computerPlayer.h"
#include <iostream>

ComputerPlayer::ComputerPlayer() : Player(), rngStart(0), rngRange(100) {}

ComputerPlayer::ComputerPlayer(const std::string& playerName) : Player(playerName), rngStart(0), rngRange(100) {}

void ComputerPlayer::resetRNG() {
    rngStart = 0;
    rngRange = 100;
}

int ComputerPlayer::getGuess() const {
    int guess = rand() % rngRange + rngStart;
    std::cout << name << " guesses " << guess << std::endl;
    return guess;
}

void ComputerPlayer::wrongGuess(int guess, int answer) {
    Player::wrongGuess(guess, answer);
    if (guess > answer) {
        adjustRangeHigh(guess);
    } else {
        adjustRangeLow(guess);
    }
}

void ComputerPlayer::adjustRangeHigh(int guess) {
    rngRange = guess - rngStart;
}

void ComputerPlayer::adjustRangeLow(int guess) {
    rngRange -= (guess + 1 - rngStart);
    rngStart = guess + 1;
}
