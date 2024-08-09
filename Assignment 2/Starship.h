// Name:Victoria Bukreev
// Student ID:104638200
#ifndef STARSHIP_H
#define STARSHIP_H
#include "Components.h"
class Starship {
private:
    PropulsionSystem propulsionSystem;
    Payload payload;
    WeaponSystem weaponSystem;
    double speed;
    double distance;
public:
    Starship(const float&, const float&, const float&, const float&, const float&, const int&, const int&);
    bool ChangeSpeed(const double&);
    void Travel(const float&, const float&);
    bool FireTorpedo(const int&);
    bool FireLaser(const float&);
    void GenerateReport() const;
};
#endif