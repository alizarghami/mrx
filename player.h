#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <ostream>
#include "location.h"
namespace mrx {

enum class COLOR{
    White,
    Black,
    Green,
    Red,
    Blue,
    Yellow
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
    Player();
    COLOR getColor();
    int findCardIndex(Card*);
    void addCard(Card*);
    void discard(Card*);
    void goTo(Location*);

    virtual const char* getType();

    friend std::ostream& operator<<(std::ostream&, Player&);
};

COLOR toCOLOR(std::string);
const char* COLRtoString(COLOR);

}
#endif // PLAYER_H
