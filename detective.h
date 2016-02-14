#ifndef DETECTIVE_H
#define DETECTIVE_H

#include "player.h"
#include "location.h"
#include "card.h"

namespace mrx {

class Detective: public Player
{
public:
    Detective(COLOR, Location*, std::vector<Card*>);
    Detective(COLOR, Location*);
    Detective(COLOR);
};

}

#endif // DETECTIVE_H
