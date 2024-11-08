

#include "vitalSigns.h"
#include <random>

// -------------------\
//  getBodyTemperature \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------

double getBodyTemperature_F()
{
    double temp;
    
    cout << "Enter a body temp(F): " << endl;
    cin >> temp;

    return temp;
}

double getRespirationRate_BPM() {

    double resp;
    cout << "Enter a BPM value: " << endl;
    cin >> resp;

    return resp;
}

double getRandomTemperature_F(){

    random_device rd;

    mt19937 generator(rd());

    uniform_real_distribution<> range(97, 99);

    return range(generator);
}

double getRandom_BPM() {

    random_device rd;

    mt19937 generator(rd());

    uniform_real_distribution<> range(12, 16);

    return range(generator);

}

