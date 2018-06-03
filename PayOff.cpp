#include "MinMax.hpp"
#include "PayOff.hpp"

PayOff::PayOff(double strike, OptionType optionType) : myStrike(strike), myOptionType(optionType)
{
}
double PayOff::operator ()(double spot) const
{
    MinMax m;
    switch (myOptionType)
    {
    case call :
        return m.max(spot-myStrike, 0.0); 
    case put:
        return m.max(myStrike-spot, 0.0); 
    default:
        throw("unknown option type found.");
    } 
}