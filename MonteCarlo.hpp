#ifndef MonteCarlo_hpp
#define MonteCarlo_hpp
#include <iostream>

using namespace std;

double SimpleMonteCarlo(string type,
                         double Expiry,
                         double Strike,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);
#endif