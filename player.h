#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "location.h"
namespace mrx {

enum class COLOR{
    White,
    Black,
    Green,
    Red,
    Blue,
    Yellow,
    MAX_COLOR
};

class Player
{
    COLOR _color;
    Location* _location;
    std::vector<Card*> _cards;

public:
    Player(COLOR, Location*, std::vector<Card*>);
    Player(COLOR, Location*);
    Player(COLOR);
    int findCardIndex(Card*);
    void addCard(Card*);
    void discard(Card*);
    void goTo(Location*);
};

}
#endif // PLAYER_H
