#ifndef MRX_H
#define MRX_H

#include "player.h"
#include "location.h"
#include "card.h"

namespace mrx {

class MrX : public Player
{
    bool _ifVisible;
public:
    MrX(COLOR, Location*, std::vector<Card*>);
    MrX(COLOR, Location*);
    MrX(COLOR);
    virtual const char* getType();
};

}
#endif // MRX_H
