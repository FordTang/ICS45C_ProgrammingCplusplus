//Ford Tang
//46564602
//ICS45C

#include <string>
#include <iostream>
#include "getinput.h"
#include "location.h"

int main()
{
    location start, closest, farthest, check;
    int count;

    start = getInput();
    std::cin >> count;

    if(count == 0)
    {
        std::cout << "Start Location: " << start.getLat() << "/" << start.getNS() << " " << start.getLon() << "/" << start.getWE() << " (" << start.getName() << ")" << std::endl;
        return 0;
    }
    
    closest = getInput();
    farthest = closest;

    count--;

    while(count > 0)
    {
        check = getInput();
        double checkDistance = start.distance(check);
        if(checkDistance < start.distance(closest))
            closest = check;
        if(checkDistance > start.distance(farthest))
            farthest = check;
        count--;
    }

std::cout << "Start Location: " << start.getLat() << "/" << start.getNS() << " " << start.getLon() << "/" << start.getWE() << " (" << start.getName() << ")" << std::endl << "Closest Location: " << closest.getLat() << "/" << closest.getNS() << " " << closest.getLon() << "/" << closest.getWE() << " (" << closest.getName() << ") (" << start.distance(closest) << " miles)" <<  std::endl << "Farthest Location: " << farthest.getLat() << "/" << farthest.getNS() << " " << farthest.getLon() << "/" << farthest.getWE() << " (" << farthest.getName() << ") (" << start.distance(farthest) << " miles)" << std::endl;
    
    return 0;
}

