#include "plan.h"

namespace mrx {

Plan::Plan()
{
}

Plan::Plan(PLAN code): _code(code)
{
}

PLAN Plan::getCode()
{
    return _code;
}

void Plan::setCode(PLAN code)
{
    _code = code;
}

void Plan::clear()
{
    _xstart.clear();
    _dstart.clear();
    _goal.clear();
}

void Plan::addXstart(Location* location)
{
    _xstart.push_back(location);
}

void Plan::addDstart(Location* location)
{
    _dstart.push_back(location);
}
void Plan::addGoal(Location* location)
{
    _goal.push_back(location);
}

bool operator==(Plan &plan, PLAN code)
{
    return (plan._code == code ? true : false);
}

std::ostream& operator<<(std::ostream& out, Plan plan)
{
    out << "Plan " << PLANtoString(plan.getCode()) <<
           "\n" << "Mr. X's Starting points:";
    for (Location* s: plan._xstart)
    {
        out << " " << s->getID();
    }

    out << "\n" << "Detective's Starting points:";

    for (Location* d: plan._dstart)
    {
        out << " " << d->getID();
    }

    out << "\n" << "Goal points:";

    for (Location* g: plan._xstart)
    {
        out << " " << g->getID();
    }

    out << "\n";
}

PLAN toPLAN(std::string text)
{
    if (text=="green")
        return PLAN::Green;
    else if (text=="yellow")
        return PLAN::Yellow;
    else if (text=="orange")
        return PLAN::Orange;
    //else
        //error
}

const char* PLANtoString(PLAN code)
{
    switch (code) {
    case PLAN::Green:
        return "Green";
    case PLAN::Yellow:
        return "Yellow";
    case PLAN::Orange:
        return "Orange";
    //default:
        //error
    }
}

}
