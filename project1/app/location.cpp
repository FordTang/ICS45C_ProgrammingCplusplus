//Ford Tang
//46564602
//ICS 45C

#include "location.h"
#include "distance.h"
#define _USE_MATH_DEFINES
#include <cmath>

location::location()
{
}

location::location(double lat, std::string ns, double lon, std::string we, std::string name)
{
    this->lat = lat;
    this->lon = lon;
    this->ns = ns;
    this->we = we;
    this->name = name;
}

double location::getLat()
{
    return lat;
}

double location::getLon()
{
    return lon;
}

std::string location::getNS()
{
    return ns;
}

std::string location::getWE()
{
    return we;
}

std::string location::getName()
{
    return name;
}

double location::getLatRad()
{
    if(this->ns == "N")
        return lat * (M_PI/180);
    else
        return -lat * (M_PI/180);
}

double location::getLonRad()
{
    if (this->we == "W")
        return lon * (M_PI/180);
    else
        return -lon * (M_PI/180);
}

double location::distance(location &location2)
{
    return calculate(this->getLatRad(), this->getLonRad(), location2.getLatRad(), location2.getLonRad());
}
