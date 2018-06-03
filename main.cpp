#include <iostream> 
#include "PayOff.hpp"
#include "SimpleMC.hpp" 
using namespace std;

int main()
{
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long numberOfPaths; 
    cout << "\nEnter expiry\n"; 
    cin >> expiry;
    cout << "\nEnter strike\n"; 
    cin >> strike;
    cout << "\nEnter spot\n"; 
    cin >> spot;
    cout << "\nEnter vol\n"; 
    cin >> vol;
    cout << "\nEnter r\n"; 
    cin >> r;
    cout << "\nNumber of paths\n"; 
    cin >> numberOfPaths;
    PayOff callPayOff(strike, PayOff::call); 
    PayOff putPayOff(strike, PayOff::put);
    double resultCall = SimpleMonteCarlo(callPayOff, 
                                            expiry,
                                            spot,
                                            vol,
                                            r, 
                                            numberOfPaths
                                            );
    double resultPut = SimpleMonteCarlo(putPayOff, 
                                            expiry,
                                            spot,
                                            vol,
                                            r, 
                                            numberOfPaths
                                            );
    cout << "the prices are " << resultCall << " for the call and " << resultPut << " for the put\n";
    return 0;
}