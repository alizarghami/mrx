#include "mrx.h"

namespace mrx {

MrX::MrX(COLOR color, Location* location, std::vector<Card*> cards)
    : Player(color,location,cards), _ifVisible(false)
{
}

MrX::MrX(COLOR color, Location* location): Player(color,location), _ifVisible(false)
{
}

MrX::MrX(COLOR color): Player(color), _ifVisible(false)
{
}

const char* MrX::getType()
{
    return "Mr. X";
}

}
