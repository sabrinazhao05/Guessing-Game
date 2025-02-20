#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
#include <cstdlib>
#include <ctime>

class ComputerPlayer : public Player {
private:
    int rngStart;
    int rngRange;

    void adjustRangeHigh(int guess);
    void adjustRangeLow(int guess);

public:
    ComputerPlayer();
    ComputerPlayer(const std::string& playerName);

    void resetRNG();
    int getGuess() const override;
    void wrongGuess(int guess, int answer) override;
};

#endif // COMPUTERPLAYER_H