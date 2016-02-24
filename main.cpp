#include <iostream>
#include <vector>
#include "card.h"
#include "player.h"
#include "parser.h"
#include "plan.h"

using namespace std;
using namespace mrx;

int main(int argc, char** argv)
{
    std::vector<Location> locations;
    std::vector<Plan> plans;
    Parser myParser(argv[1]);

    myParser.openFile(FILETYPE::Board);
    myParser.boardReader(locations);
    myParser.openFile(FILETYPE::Plan);
    myParser.planReader(plans, locations);

    for(Location l: locations)
    {
        cout << l;
    }

    for(Plan p: plans)
    {
        cout << p;
    }

    return 0;
}

