#ifndef UT_SIMPLE_MC_H 
#define UT_SIMPLE_MC_H 
#include "PayOff.hpp"
double SimpleMonteCarlo(const PayOff& payOff, 
                        double expiry,
                        double spot,
                        double vol,
                        double r,
                        unsigned long NumberOfPaths
                        );
#endif