//Ford Tang
//46564602
//ICS 45C

#include "getinput.h"
#include "location.h"

std::string lon, lat, name;

location getInput()
{
    std::cin >> lon >> lat;
    std::getline(std::cin, name);
    return location(std::stod(lon.substr(0, lon.find("/"))), lon.substr(lon.size() - 1), std::stod(lat.substr(0, lat.find("/"))), lat.substr(lat.size() - 1), name.substr(1, name.size() - 1));

}
