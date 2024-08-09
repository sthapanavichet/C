// Name: Sthapanavichet Long 
// Student ID: 137580221
#include <iostream>
#include "Warbird.h"
using namespace std;
// constructor
Warbird::Warbird(const float& fuelLevel, const float& lightLevel, const float& passengersMass, const float& cargosMass, const float& workstationsMass, const int& numTorpedo, const int& numLaser) :
    propulsionSystem1(fuelLevel, lightLevel), propulsionSystem2(fuelLevel, lightLevel),
    payload(passengersMass, cargosMass, workstationsMass),
    weaponSystem1(numTorpedo, numLaser), weaponSystem2(numTorpedo, numLaser),
    speed(0),
    distance(0) {}

bool Warbird::ChangeSpeed(const double& deltaSpeed) {
    double energy;
    energy = 0.5 * payload.GetMass() * deltaSpeed * deltaSpeed; // energy required to change speed
    if(propulsionSystem1.ConsumeFuel(energy/2)) { // divide the energy into 2 halves because there is two propulsion system
        if(propulsionSystem2.ConsumeFuel(energy/2)) {
            speed += deltaSpeed;
            return true; // return true only if both system are working else return false
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    return false;
}

void Warbird::Travel(const float& time, const float& lightLevel) {
    distance += speed * time; // increment distance travelled
    propulsionSystem1.SetLightLevel(lightLevel);
    propulsionSystem2.SetLightLevel(lightLevel);
    propulsionSystem1.GenerateFuel(time);
    propulsionSystem2.GenerateFuel(time);
}

bool Warbird::FireTorpedo(const int& numTorpedos) {
    if(numTorpedos % 2 == 0) {
        if (weaponSystem1.FireTorpedos(numTorpedos / 2)) { // checking if torpedoes required is enough or not
            if (weaponSystem2.FireTorpedos(numTorpedos / 2)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    else {
        if (weaponSystem1.FireTorpedos(numTorpedos / 2)) { // checking if torpedoes required is enough or not
            if (weaponSystem2.FireTorpedos(numTorpedos / 2 + 1)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return false;
}

bool Warbird::FireLaser(const float& time) {
    if(propulsionSystem1.ConsumeFuel(weaponSystem2.FireLaser(time))) { // checking if energy required is enough or not
        if(propulsionSystem1.ConsumeFuel(weaponSystem2.FireLaser(time))) {
            return true;
        } else {
        return false;
        }
    } else {
        return false;
    }
    return false;
}  

void Warbird::GenerateReport() const { // output function
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The war bird is travelling at " << speed << "m/s and has travelled " << distance << "m." << endl;
    propulsionSystem1.GenerateReport();
    propulsionSystem2.GenerateReport();
    payload.GenerateReport();
    weaponSystem1.GenerateReport();
    weaponSystem2.GenerateReport();
    cout << endl;
}
