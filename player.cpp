#include "player.h"

namespace mrx {

Player::Player(COLOR color, Location* location, std::vector<Card*> cards)
    : _color(color), _location(location), _cards(cards)
{
}

Player::Player(COLOR color, Location* location): Player::Player(color,location,{})
{
}

Player::Player(COLOR color): Player::Player(color,0,{})
{
}

int Player::findCardIndex(Card* card)
{
    for(uint i=0; i<_cards.capacity(); i++)
    {
        if (_cards[i]==card)
            return i;
    }
    return -1;
}

void Player::addCard(Card* card)
{
    _cards.push_back(card);
}

void Player::discard(Card* card)
{
    int index = this->findCardIndex(card);
    _cards[index] = card;
}

void Player::goTo(Location* location)
{
    _location = location;
}

}
