// Name: Hasan & Mubassir Mohmed Sapa
// Student ID: 120597224 & 118160225 (respectively)
#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <iomanip>
#include <iostream>
// The Payload

class Payload
{
private:
    float massOfPassanger;
    float massOfCargo;
    float massOfWorkStation;

public:
    Payload();
    Payload(const float& passanger, const float& cargo, const float& station);

    float GetMass() const;
    void AddPassangers(const float& _newMass);
    void AddCargos(const float& _newMass);
    void AddWorkStations(const float& _newMass);
    void GenerateReport() const;
};

// The Propulsion System:

class PropulsionSystem
{
private:
    float fuelLevel; // kg of matter/ anto-matter
    const float FUELTANKCAPACITY = 1000.0;//kg of matter/antimatter
    const double SPEEDOFLIGHT = 299792458;
    float lightToFuelConversation;
    float lightLevel; // MAX 1.0

public:
    PropulsionSystem();
    PropulsionSystem(const float& _fuel, const float& _light);

    bool ConsumeFuel(const double& _energy);
    void AddFuel(const float& _fuel);
    void GenerateFuel(const float& _time);
    void SetLightLevel(const float& _lightLevel);
    void GenerateReport() const;
};

// The Weapon System

class WeaponSystem
{
private:
    int numOfTorpedos;
    int numOfLaserCannons; // shoots laser we can only increase the canon.
    const int MAXTORPEDO = 110;
    const int MAXLASER = 10;
    const double ENERGYPERSECOND = 1000000000000.0;

public:
    WeaponSystem();
    WeaponSystem(const int& _torpedos, const int& _laser);

    bool FireTorpedos(const int& _torpedos);
    double FireLaser(const float& _time);
    void AddTopedos(const int& _torpedos);
    void AddLaser(const int& _laser);
    void GenerateReport() const;
};

#endif