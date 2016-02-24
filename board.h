#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "location.h"
#include "card.h"
#include "plan.h"
#include "player.h"
#include "parser.h"

namespace mrx {

class Board
{
    std::vector<Plan> _plans;
    std::vector<Location> _map;
    std::vector<Card> _cards;
    std::vector<Player> _players;

    Plan _plan;
    std::vector<Card*> _available;
    std::vector<Card*> _discarded;
public:
    Board();
    Board(std::string);
    void initialize(std::string);
    void choosePlan();
};

}

#endif // BOARD_H
