// Name: Mirac Ozcan
// Student ID: 181468216
#ifndef CARGO_H
#define CARGO_H

#include "Components.h"

class Cargo {
private:
    PropulsionSystem propulsion;
    Payload payload[2];
    double speed;
    double distance;

public:
    Cargo(const float& fuelLevel, const float& lightLevel, const float& passengerMass, const float& cargoMass, const float& workstationMass);
    bool ChangeSpeed(const double& newSpeed);
    void Travel(const float& time, const float& lightLevel);
    void GenerateReport() const;
};

#endif
