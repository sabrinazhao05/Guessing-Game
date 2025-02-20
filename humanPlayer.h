#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"
#include <iostream>

class HumanPlayer : public Player {
public:
    HumanPlayer();
    HumanPlayer(const std::string& playerName);

    int getGuess() const override;
};

#endif // HUMANPLAYER_H