#include <iostream>
#include <cmath>
#include "main.hpp"

using namespace std;
// Monte carlo simulation of call options
double SimpleMonteCarlo1(string type,
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

int main()
{
    string type;
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nWhich do you want to calcurate, call or put? please answer 'call' or 'put'\n";
    cin >> type;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nEnter r\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    // do the monte carlo simulation
    double result = SimpleMonteCarlo1(type,
                                      Expiry,
                                      Strike,
                                      Spot,
                                      Vol,
                                      r, 
                                      NumberOfPaths);
    // outputs price
    cout << "the price is " << result << "\n";
    double tmp;
    cin >> tmp;
    exit(0);
}
