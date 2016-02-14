#ifndef INITCARD_H
#define INITCARD_H

#include "location.h"

namespace mrx {

class InitCard
{
    Location* _start;
public:
    InitCard(Location*);
};

}
#endif // INITCARD_H
