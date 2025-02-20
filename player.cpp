#include "player.h"
#include <iostream>

Player::Player() : name(""), wins(0) {}

Player::Player(const std::string& playerName) : name(playerName), wins(0) {}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string& playerName) {
    name = playerName;
}

int Player::getWins() const {
    return wins;
}

void Player::wrongGuess(int guess, int answer) {
    if (guess > answer) {
        std::cout << "Your guess is too high." << std::endl;
    } else {
        std::cout << "Your guess is too low." << std::endl;
    }
}

void Player::endRound(bool won) {
    if (won) {
        ++wins;
    }
}

bool Player::operator>(const Player& other) const {
    return wins > other.wins;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.name << "\nNumber of Wins: " << player.wins;
    return os;
}
