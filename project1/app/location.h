//Ford Tang
//46564602
//ICS 45C

#ifndef _location
#define _location
#include <string>

class location
{
    public:
        location();
        //Default constructor

        location(double lat, std::string ns, double lon, std::string we, std::string name);
        //Constructor with data
        
        double getLat();
        //returns the latitude for the object

        double getLon();
        //returns the longitude for the object

        std::string getNS();
        //returns either N or S for the object, North or South respectively

        std::string getWE();
        //returns either the W or E for the object, West or East respectively

        std::string getName();
        //returns the name of the object
        
        double getLatRad();
        //returns the latitude in radians

        double getLonRad();
        //returns the longitude in radians

        double distance(location &location2);
        //takes a reference to a location object and returns the distance between itself and the reference location object
       
    private:
        double lat, lon;
        std::string ns, we, name;
};

#endif
