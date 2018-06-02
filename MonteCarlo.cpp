#include <cmath>
#include "BoxMuller.hpp"
#include <iostream>

using namespace std;

double SimpleMonteCarlo(string type,
                         double Expiry,
                         double Strike,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths)
{
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;
    if (type == "call"){
        for (unsigned long i = 0; i < NumberOfPaths; i++)
        {
            double thisGaussian = GetOneGaussianByBoxMuller();
            thisSpot = movedSpot*exp(rootVariance*thisGaussian);
            double thisPayoff = thisSpot - Strike;
            thisPayoff = thisPayoff >0 ? thisPayoff : 0;
            runningSum += thisPayoff;
        }
    }
    else if(type == "put"){
        for (unsigned long i = 0; i < NumberOfPaths; i++)
        {
            double thisGaussian = GetOneGaussianByBoxMuller();
            thisSpot = movedSpot*exp(rootVariance*thisGaussian);
            double thisPayoff = Strike - thisSpot;
            thisPayoff = thisPayoff >0 ? thisPayoff : 0;
            runningSum += thisPayoff;
        }
    }
    else {
        cout << "\nplease answer 'call' or 'put'\n";
        exit(0);
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}