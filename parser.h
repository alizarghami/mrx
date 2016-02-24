#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <cassert>
#include "pugi/pugixml.hpp"
#include "card.h"
#include "player.h"
#include "mrx.h"
#include "detective.h"
#include "location.h"
#include "plan.h"


namespace mrx {

const char* const ROOT_NODE = "root";
const char* const CARD_NODE = "card";
const char* const COUNT_ATT = "count";
const char* const TRNS_NODE = "transport";
const char* const SPCL_NODE = "special";
const char* const PLYR_NODE = "player";
const char* const COLR_NODE = "color";
const char* const PTYPE_ATT = "type";
const char* const NODE_NODE = "node";
const char* const PATH_NODE = "paths";
const char* const PLAN_NODE = "plan";

enum class FILETYPE{
    Card,
    Player,
    Plan,
    Board
};

class Parser
{
    std::string _path;
    pugi::xml_document _tree;
public:
    Parser(std::string);
    void openFile(FILETYPE);
    void cardReader(std::vector<Card>&);
    void playerReader(std::vector<Player>&);
    void boardReader(std::vector<Location>&);
    void planReader(std::vector<Plan>&, std::vector<Location>&);
};

}
#endif // PARSER_H
