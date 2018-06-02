#include <iostream>
#include <cmath>
#include "MonteCarlo.hpp"
#include "BoxMuller.hpp"

using namespace std;

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
    double result = SimpleMonteCarlo(type,
                                      Expiry,
                                      Strike,
                                      Spot,
                                      Vol,
                                      r, 
                                      NumberOfPaths);
    // outputs price
    cout << "the price is " << result << "\n";
    return 0;
}
