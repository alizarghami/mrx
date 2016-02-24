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

TRANSPORTATION Card::getTransport()
{
    return _trans;
}

SPECIAL Card::getSpecial()
{
    return _special;
}

std::ostream& operator<<(std::ostream &out, Card &card)
{
    out << "Card ID: " << card.getID() << "\n" <<
           "Transportation method: " << TRANStoString(card.getTransport()) << "\n" <<
           "Special move: " << SPCLtoString(card.getSpecial()) << "\n";

    return out;
}

bool operator==(Card card1, Card card2)
{
    return (card1.getID()==card2.getID());
}

TRANSPORTATION toTRANSPORTATION(std::string text)
{

    if (text=="taxi")
        return TRANSPORTATION::Taxi;
    else if (text=="train")
        return TRANSPORTATION::Train;
    else if (text=="plane")
        return TRANSPORTATION::Plane;
    //else
        //error
}

SPECIAL toSPECIAL(std::string text)
{
    if (text=="double")
        return SPECIAL::Double;
    else if (text=="undercover")
        return SPECIAL::Undercover;
    else if (text=="investigate")
        return SPECIAL::Investigate;
    else if (text=="operation")
        return SPECIAL::Operation;
    //else
        //error
}

const char* TRANStoString(TRANSPORTATION trans)
{
    switch (trans) {
    case TRANSPORTATION::Taxi:
        return "Taxi";
    case TRANSPORTATION::Train:
        return "Train";
    case TRANSPORTATION::Plane:
        return "Plane";
    //default:
        //error
    }
}

const char* SPCLtoString(SPECIAL spcl)
{
    switch (spcl) {
    case SPECIAL::Double:
        return "Double Move";
    case SPECIAL::Investigate:
        return "Investigation";
    case SPECIAL::Undercover:
        return "Undercover movement";
    case SPECIAL::Operation:
        return "Special Operation";
    //default:
        //error
    }
}

}
