#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    int wins;

public:
    Player();
    Player(const std::string& playerName);
    virtual ~Player() = default;

    std::string getName() const;
    void setName(const std::string& playerName);

    int getWins() const;

    virtual int getGuess() const = 0;
    virtual void wrongGuess(int guess, int answer);
    virtual void endRound(bool won);

    bool operator>(const Player& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif 
