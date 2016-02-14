#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "location.h"
#include "card.h"
#include"initcard.h"

namespace mrx {

enum class PLAN{
    Green,
    Yellow,
    Orange,
    MAX_PLANS
};

class Board
{
    PLAN _plan;
    std::vector<Location> _board;
    std::vector<Card> _cards;
    std::vector<InitCard> _initCards;
public:
    Board(std::string, PLAN, std::string, std::string);
    void ParseBoardInfo(std::string, PLAN);
    void ParseCardInfo(std::string);
    void ParseInitCardInfo(std::string);
};

}

#endif // BOARD_H
