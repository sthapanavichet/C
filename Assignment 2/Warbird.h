// Name: Sthapanavichet Long 
// Student ID: 137580221
#ifndef WARBIRD_H
#define WARBIRD_H
#include "Components.h"
class Warbird {
private:
    PropulsionSystem propulsionSystem1;
    PropulsionSystem propulsionSystem2;
    WeaponSystem weaponSystem1;
    WeaponSystem weaponSystem2;
    Payload payload;
    double speed;
    double distance;
public:
    Warbird(const float&, const float&, const float&, const float&, const float&, const int&, const int&);
    bool ChangeSpeed(const double&);
    void Travel(const float&, const float&);
    bool FireTorpedo(const int&);
    bool FireLaser(const float&);
    void GenerateReport() const;
};

#endif