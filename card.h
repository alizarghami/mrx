#ifndef CARD_H
#define CARD_H

namespace mrx {

enum class TRANSPORTATION{
    Taxi,
    Train,
    Plane
};

enum class SPECIAL{
    A,
    B,
    C,
    D
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

    friend bool operator==(Card, Card);
};

}
#endif // CARD_H
