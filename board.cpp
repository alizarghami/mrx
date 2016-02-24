#include "board.h"

namespace mrx {

Board::Board()
{
}

Board::Board(std::string path)
{
    this->initialize(path);
}

void Board::initialize(std::string path)
{
    Parser parser(path);

    _cards.clear();
    _map.clear();
    _plans.clear();
    _players.clear();

    parser.openFile(FILETYPE::Card);
    parser.cardReader(_cards);

    parser.openFile(FILETYPE::Board);
    parser.boardReader(_map);

    parser.openFile(FILETYPE::Plan);
    parser.planReader(_plans, _map);

    parser.openFile(FILETYPE::Player);
    parser.playerReader(_players);
}

void Board::choosePlan()
{
    //This function should be modified appropriatly
    int index;
    std::cin >> index;
    _plan = _plans[index];
}

}
