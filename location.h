#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include "card.h"

namespace mrx {

class Location
{
    int _id;
    std::string _name;
    bool _ifOccupied = false;
    bool _ifStart;
    bool _ifGoal;
    std::vector<Location*> _taxi;
    std::vector<Location*> _train;
    std::vector<Location*> _plane;

public:
    Location(int, std::string, bool, bool, std::vector<Location*>, std::vector<Location*>, std::vector<Location*>);
    Location(int,std::string, bool,bool);
    Location(int, std::string);

    void addPath(Location*, TRANSPORTATION);


};

}
#endif // LOCATION_H
