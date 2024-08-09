// Name: Hasan & Mubassir Mohmed Sapa
// Student ID: 120597224 & 118160225 (respectively)

#include <iostream>
#include "Components.h"

// The Payload
// constructors
Payload::Payload()
{
    massOfPassanger = 0.0;
    massOfCargo = 0.0;
    massOfWorkStation = 0.0;
}

Payload::Payload(const float& _passanger, const float& _cargo, const float& _station)
{
    massOfPassanger = _passanger;
    massOfCargo = _cargo;
    massOfWorkStation = _station;
}
// get mass
float Payload::GetMass() const
{
    return massOfPassanger + massOfCargo + massOfWorkStation;
}
// setter functions
void Payload::AddPassangers(const float& _newMass)
{
    massOfPassanger += _newMass;
}

void Payload::AddCargos(const float& _newMass)
{
    massOfCargo += _newMass;
}

void Payload::AddWorkStations(const float& _newMass)
{
    massOfWorkStation += _newMass;
}

void Payload::GenerateReport() const // output
{
    std::cout.setf(std::ios::fixed);
	std::cout.precision(2); // print to 2 decmial places
    std::cout << "Payload: mass of passengers: " << massOfPassanger << "kg, mass of cargo: " << massOfCargo << "kg, mass of workstations: " << massOfWorkStation << "kg." << std::endl;
}

// The Propulsion System:
// constructors
PropulsionSystem::PropulsionSystem()
{
    fuelLevel = 0;
    lightLevel = 0;
}
PropulsionSystem::PropulsionSystem(const float& _fuel, const float& _light)
{
    fuelLevel = _fuel;
    lightLevel = _light;
}

bool PropulsionSystem::ConsumeFuel(const double& _energy)
{
    double massRequired;
    massRequired = _energy / (SPEEDOFLIGHT * SPEEDOFLIGHT);
    // fuelLevel -= (speedOfLight * speedOfLight);
    if (massRequired <= fuelLevel) // validation
    {
        fuelLevel -= massRequired;
        return true;
    }
    else
        return false;
}

void PropulsionSystem::AddFuel(const float& _fuel)
{
    fuelLevel += _fuel;
    if(fuelLevel > FUELTANKCAPACITY) { // keeping fuel level at capacity
        fuelLevel = FUELTANKCAPACITY;
    }

}
void PropulsionSystem::GenerateFuel(const float& _time)
{
    fuelLevel += lightLevel * _time;
    if(fuelLevel > FUELTANKCAPACITY) { // keeping fuel level at capacity
        fuelLevel = FUELTANKCAPACITY;
    }
}
void PropulsionSystem::SetLightLevel(const float& _lightLevel)
{
    lightLevel = _lightLevel; 
}
void PropulsionSystem::GenerateReport() const // output
{
    std::cout.setf(std::ios::fixed);
	std::cout.precision(2); // print to 2 decmial places
    std::cout << "Propulsion: fuel level: " << fuelLevel << "kg" << " of matter/anti-matter, light level: " << lightLevel << "." << std::endl;
}

// The Weapon System
// consstructors
WeaponSystem::WeaponSystem()
{
    numOfTorpedos = 0;
    numOfLaserCannons = 0;
}
WeaponSystem::WeaponSystem(const int& _torpedos, const int& _laser)
{
    numOfTorpedos = _torpedos;
    numOfLaserCannons = _laser;
}

bool WeaponSystem::FireTorpedos(const int& _torpedos) 
{
    if (_torpedos > numOfTorpedos) // checking for torpedoes available 
        return false;
    else {
        numOfTorpedos -= _torpedos;
        return true;
    }
    return false;
}
double WeaponSystem::FireLaser(const float& _time)
{
    // numOfLaserCannons -= enegryPerSecFireLaser * time_;
    return ENERGYPERSECOND * _time * numOfLaserCannons;
}
void WeaponSystem::AddTopedos(const int& _torpedos)
{
    numOfTorpedos += _torpedos;
    if(numOfTorpedos > MAXTORPEDO) { // validation
        numOfTorpedos = MAXTORPEDO;
    }
}
void WeaponSystem::AddLaser(const int& _laser)
{
    numOfLaserCannons += _laser;
    if(numOfLaserCannons > MAXLASER) { // validation
        numOfLaserCannons = MAXLASER;
    }
}
void WeaponSystem::GenerateReport() const // output
{
    std::cout.setf(std::ios::fixed);
	std::cout.precision(2); // print to 2 decmial places
    std::cout << "Weapon: number of laser cannons: " << numOfLaserCannons << ", number of torpedoes: " << numOfTorpedos << "." << std::endl;
}
