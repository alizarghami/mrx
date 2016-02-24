#include "parser.h"

namespace mrx {

Parser::Parser(std::string path): _path(path)
{
}

void Parser::openFile(FILETYPE type)
{
    std::string fullpath;

    switch (type) {
    case FILETYPE::Card:
        fullpath = _path + "/card.xml";
        break;
    case FILETYPE::Player:
        fullpath = _path + "/player.xml";
        break;
    case FILETYPE::Plan:
        fullpath = _path + "/plan.xml";
        break;
    case FILETYPE::Board:
        fullpath = _path + "/board.xml";
        break;
    }

    _tree.load_file(fullpath.c_str());
    // error checking here !!!
}

void Parser::cardReader(std::vector<Card>& cards)
{
    cards.clear();
    TRANSPORTATION trans;
    SPECIAL special;
    int count = 0;
    for(pugi::xml_node node : _tree.child(ROOT_NODE).children(CARD_NODE))
    {
        count = node.attribute(COUNT_ATT).as_int();
        trans = toTRANSPORTATION(node.child_value(TRNS_NODE));
        special = toSPECIAL(node.child_value(SPCL_NODE));
        for(;count>0;count--)
            cards.push_back(Card(trans,special));
    }
}

void Parser::playerReader(std::vector<Player>& players)
{
    players.clear();
    for (pugi::xml_node node: _tree.child(ROOT_NODE).children(PLYR_NODE))
    {
        COLOR color = toCOLOR(node.child_value(COLR_NODE));
        const char* type = node.attribute(PTYPE_ATT).value();
        if(type[0] == 'x')
            players.push_back(MrX(color));
        else if(type[0] == 'd')
            players.push_back(Detective(color));
        //else
            //error

    }
}

void Parser::boardReader(std::vector<Location>& locations)
{
    int count = _tree.child(ROOT_NODE).attribute(COUNT_ATT).as_int();
    locations.clear();
    locations.resize(count);

    int id;
    std::string name;
    int dest;
    TRANSPORTATION trans;

    for(pugi::xml_node node: _tree.child(ROOT_NODE).children(NODE_NODE))
    {
        id = node.attribute("id").as_int();
        name = node.child_value("name");
        locations[id] = Location(id,name);
        for(pugi::xml_node path: node.child(PATH_NODE).children())
        {
            trans = toTRANSPORTATION(path.name());
            dest = atoi(path.child_value());
            locations[id].addPath(&locations[dest],trans);
        }
    }
}

void Parser::planReader(std::vector<Plan>& plans, std::vector<Location>& locations)
{
    int index;
    PLAN code;
    Plan temp;

    for(pugi::xml_node node: _tree.child(ROOT_NODE).children(PLAN_NODE))
    {
        temp.clear();
        code = toPLAN(node.attribute(COLR_NODE).as_string());
        temp.setCode(code);
        for(pugi::xml_node xstart: node.child("xstart").children("id"))
        {
            index = atoi(xstart.value());
            temp.addXstart(&locations[index]);
        }

        for(pugi::xml_node dstart: node.child("dstart").children("id"))
        {
            index = atoi(dstart.value());
            temp.addDstart(&locations[index]);
        }

        for(pugi::xml_node goal: node.child("goal").children("id"))
        {
            index = atoi(goal.value());
            temp.addGoal(&locations[index]);
        }

        plans.push_back(temp);
    }
}

}
