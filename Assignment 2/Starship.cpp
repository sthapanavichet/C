// Name: Victoria Bukreev
// Student ID: 104638200
#include <iostream>
#include "Starship.h"

Starship::Starship(const float& fuelLevel, const float& lightLevel, const float& passengersMass, const float& cargosMass, const float& workstationsMass, const int& numTorpedos, const int& numLasers) :
	propulsionSystem(fuelLevel, lightLevel), payload(passengersMass, cargosMass, workstationsMass), weaponSystem(numTorpedos, numLasers),
	speed(0), distance(0) {}

bool Starship::ChangeSpeed(const double& deltaSpeed) {
	double energy;
	energy = 0.5 * payload.GetMass() * deltaSpeed * deltaSpeed; // energy required = 1/2 * m * v^2
	if(propulsionSystem.ConsumeFuel(energy)){ // validation on the energy available
		speed += deltaSpeed;
		return true;
	}
	else {
		return false;
	}
	return false;
}

void Starship::Travel(const float& time, const float& lightLevel) {
	distance += speed * time; // distance travelled = velocity * time
	propulsionSystem.GenerateFuel(time);
	propulsionSystem.SetLightLevel(lightLevel);
}

bool Starship::FireTorpedo(const int& numTorpedos) {
	if (!weaponSystem.FireTorpedos(numTorpedos)) { // validation on torpedoes available
		return false;
	}
	 return true;
}

bool Starship::FireLaser(const float& time) {
	if (!propulsionSystem.ConsumeFuel(weaponSystem.FireLaser(time))) { // validation on energy required to shoot laser cannons
		return false;
	}
	return true;
}

void Starship::GenerateReport() const {
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	std::cout << "The star ship is travelling at " << speed << "m/s " << "and has travelled " << distance << "m." << std::endl;
	propulsionSystem.GenerateReport();
	payload.GenerateReport();
	weaponSystem.GenerateReport();
	std::cout << std::endl;
}
