#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>

namespace mrx {

enum TRANSPORTATION{
    Taxi,
    Train,
    Plane
};

enum class SPECIAL{
    Double,
    Undercover,
    Investigate,
    Operation
};

class Card
{
    static int total;
    int _id;
    TRANSPORTATION _trans;
    SPECIAL _special;
public:
    Card(TRANSPORTATION, SPECIAL);
    int getID();
    TRANSPORTATION getTransport();
    SPECIAL getSpecial();

    friend std::ostream& operator<<(std::ostream&, Card&);
    friend bool operator==(Card, Card);
};

TRANSPORTATION toTRANSPORTATION(std::string);
SPECIAL toSPECIAL(std::string);
const char* TRANStoString(TRANSPORTATION);
const char* SPCLtoString(SPECIAL);

}
#endif // CARD_H
