#include "location.h"

namespace mrx {

Location::Location(int id, std::string name, bool ifStart, bool ifGoal,
                   std::vector<Location*> taxi, std::vector<Location*> train, std::vector<Location*> plane)
    :_id(id), _name(name), _ifStart(ifStart), _ifGoal(ifGoal), _taxi(taxi), _train(train), _plane(plane)
{
}

Location::Location(int id, std::string name, bool ifStart, bool ifGoal): Location::Location(id,name,ifStart,ifGoal,{},{},{})
{
}

Location::Location(int id, std::string name): Location::Location(id,name,false,false,{},{},{})
{
}

void Location::addPath(Location* destination, TRANSPORTATION type)
{
    switch (type) {
    case TRANSPORTATION::Taxi:
        _taxi.push_back(destination);
        break;
    case TRANSPORTATION::Train:
        _train.push_back(destination);
        break;
    case TRANSPORTATION::Plane:
        _plane.push_back(destination);
        break;
    }
}

}
