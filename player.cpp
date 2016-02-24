#include "player.h"
#include <typeinfo>
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

Player::Player()
{
}

COLOR Player::getColor()
{
    return _color;
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

const char* Player::getType()
{
    return "Player";
}

std::ostream& operator<<(std::ostream& out, Player& player)
{
    out << "Player's color is " << COLRtoString(player.getColor()) <<
           " and the player is a " << player.getType() <<"\n";
    return out;
}

COLOR toCOLOR(std::string text)
{
    if (text == "white")
        return COLOR::White;
    else if(text == "red")
        return COLOR::Red;
    else if(text == "blue")
        return COLOR::Blue;
    else if(text == "green")
        return COLOR::Green;
    else if(text == "yellow")
        return COLOR::Yellow;
    else if(text == "black")
        return COLOR::Black;
    //else
        //error
}

const char* COLRtoString(COLOR color)
{
    switch (color) {
    case COLOR::White:
        return "White";
    case COLOR::Black:
        return "Black";
    case COLOR::Red:
        return "Red";
    case COLOR::Blue:
        return "Blue";
    case COLOR::Green:
        return "Green";
    case COLOR::Yellow:
        return "Yellow";
    //default:
        //error;
    }
}

}
