#ifndef PLAN_H
#define PLAN_H

#include <ostream>
#include <vector>
#include "location.h"

namespace mrx {

enum class PLAN{
    Green,
    Yellow,
    Orange,
    MAX_PLANS
};

class Plan
{
    PLAN _code;
    std::vector<Location*> _dstart;
    std::vector<Location*> _xstart;
    std::vector<Location*> _goal;
public:
    Plan();
    Plan(PLAN);
    PLAN getCode();
    void setCode(PLAN);
    void clear();
    void addXstart(Location*);
    void addDstart(Location*);
    void addGoal(Location*);

    friend bool operator==(Plan&, PLAN);
    friend std::ostream& operator<<(std::ostream&, Plan);
};

PLAN toPLAN(std::string);
const char* PLANtoString(PLAN);

}
#endif // PLAN_H
