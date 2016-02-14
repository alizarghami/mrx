#include "card.h"

namespace mrx {

int Card::total = 0;

Card::Card(TRANSPORTATION trans, SPECIAL special): _id(total++), _trans(trans), _special(special)
{
}

int Card::getID()
{
    return _id;
}

bool operator==(Card card1, Card card2)
{
    return (card1.getID()==card2.getID());
}

}
