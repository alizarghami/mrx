#include "board.h"

namespace mrx {

Board::Board(std::string boardPath, PLAN plan, std::string cardPath, std::string initCardPath)
{
    ParseBoardInfo(boardPath, plan);
    ParseCardInfo(cardPath);
    ParseInitCardInfo(initCardPath);
}

void Board::ParseBoardInfo(std::string path, PLAN plan)
{

}

void Board::ParseCardInfo(std::string path)
{

}

void Board::ParseInitCardInfo(std::string path)
{

}

}
