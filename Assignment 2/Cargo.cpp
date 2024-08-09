// Name: Mirac Ozcan
// Student ID: 181468216

#include <iostream>
#include "Cargo.h"

using namespace std;

Cargo::Cargo(const float& fuelLevel, const float& lightLevel, const float& passengerMass, const float& cargoMass, const float& workstationMass)
    : propulsion(fuelLevel, lightLevel), payload{Payload(passengerMass, cargoMass, workstationMass), Payload(passengerMass, cargoMass, workstationMass)},
     speed(0), distance(0) {}

bool Cargo::ChangeSpeed(const double& newSpeed) {
    double energyRequired = 0.5 * (payload[0].GetMass()+payload[1].GetMass()) * newSpeed * newSpeed;
    bool ret = propulsion.ConsumeFuel(energyRequired); // checking to see if fuel needed is available
    if (!ret) {
        return false;
    }
    else if(ret) {
        speed += newSpeed;
    }
    return true; // return true if ret is true;
}

void Cargo::Travel(const float& time, const float& lightLevel) {
    distance += speed * time;
    propulsion.SetLightLevel(lightLevel); // set light level and generate fuel
    propulsion.GenerateFuel(time);
    
}

void Cargo::GenerateReport() const { // output
    cout.setf(ios::fixed);
	cout.precision(2); // print floats to 2 decimal places
    cout << "The cargo ship is travelling at " << speed << "m/s ";
    cout << "and has travelled " << distance / 1000 << "km." << endl;
    payload[0].GenerateReport();
    payload[1].GenerateReport();
    propulsion.GenerateReport();
    cout << endl;
}

