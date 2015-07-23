//Ford Tang
//46564602
//ICS 45C

#include "distance.h"

double dlat, dlon, a, c, d;
const double R = 3959.9;

double calculate(double lat1, double lon1, double lat2, double lon2)
    {
        dlat = lat1 - lat2;
        dlon = lon1 - lon2;
        a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2),2);
        c = 2 * atan2(sqrt(a), sqrt(1 - a));
        d = R * c;

        return d;
    }
