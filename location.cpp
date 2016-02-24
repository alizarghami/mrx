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

Location::Location(): Location::Location(-1,"",false,false,{},{},{})
{
}

int Location::getID()
{
    return _id;
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

std::ostream& operator<<(std::ostream& out, Location location)
{
    out << "Location Id: " << location._id << "\n" <<
           "Name: " << location._name << "\n" <<
           "Taxi routs to:";
    for(Location* l: location._taxi)
    {
        out << " " << l->_id;
    }
    out << "\n" << "Train routs to:";
    for(Location* l: location._train)
    {
        out << " " << l->_id;
    }
    out << "\n" << "Plane routs to:";

    for(Location* l: location._plane)
    {
        out << " " << l->_id;
    }
    out << "\n";
}

}
