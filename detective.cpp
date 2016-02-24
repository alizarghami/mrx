#include "detective.h"

namespace mrx {


Detective::Detective(COLOR color, Location* location, std::vector<Card*> cards): Player(color,location,cards)
{
}

Detective::Detective(COLOR color, Location* location): Player(color,location)
{
}

Detective::Detective(COLOR color): Player(color)
{
}

const char* Detective::getType()
{
    return "Detective";
}

}
