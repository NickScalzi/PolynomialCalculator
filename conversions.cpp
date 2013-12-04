//Nick Scalzi

#include "conversions.h"
#include <sstream>
#include "math.h"

int stringToInt(std::string s)
{
    int i = 0;
    int n =0;

    while(i<s.length())
    {
        n+=pow(10,s.length()-i-1) *( s.at(i) -48);
        i++;
    }

    return n;
}

std::string intToString (int i)
{
    std::stringstream ss;
    std::string s="0";

    ss<< i;
    s= ss.str();

    return s;
}
