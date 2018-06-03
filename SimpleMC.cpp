#include "PayOff.hpp"
#include "BoxMuller.hpp" 
#include <cmath>

double SimpleMonteCarlo(const PayOff& thePayOff, 
                        double expiry,
                        double spot,
                        double vol,
                        double r,
                        unsigned long numberOfPaths)
{
    double variance = vol*vol*expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = spot*exp(r*expiry +itoCorrection); 
    double thisSpot;
    double runningSum=0;
    for (unsigned long i=0; i < numberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller(); 
        thisSpot = movedSpot*exp( rootVariance*thisGaussian); 
        double thisPayOff = thePayOff(thisSpot);
        runningSum += thisPayOff;
    }
    double mean = runningSum / numberOfPaths; 
    mean *= exp(-r*expiry);
    return mean;
}