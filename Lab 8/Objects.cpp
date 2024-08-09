#include "MoonObject.h"
#include "EarthObject.h"
#include <iostream>
// EarthObject Class
EarthObject::EarthObject () {
    initHeight = 0;
    HorVel = 0;
}

EarthObject::EarthObject (double _initHeight, double _HorVel) {
    if(_initHeight > 0 && _HorVel > 0) { // validation
        initHeight = _initHeight;
        HorVel = _HorVel;
    }
    else {
        std::cout << "Invalid Value" << std::endl;
    }
}

bool EarthObject::setHeight(double _initHeight) {
    if(_initHeight > 0) { // validation
        initHeight = _initHeight;
        return true;
    }
    return false; // return false by default
}

bool EarthObject::setHorVel(double _HorVel) {
    if(_HorVel > 0) { // validation
        HorVel = _HorVel;
        return true;
    }
    return false; // return false by default
}

double EarthObject::getXPos(double time) {
    double retVal = HorVel * time;
    return retVal;
}

double EarthObject::getYPos(double time) {
    double retVal = initHeight - 0.5 * Gravity * time * time;
    return retVal;
}

// MoonObject class
MoonObject::MoonObject() {
    initHeight = 0;
    HorVel = 0;
}

MoonObject::MoonObject (double _initHeight, double _VerVel, double _HorVel) {
    if(_initHeight > 0) {
        initHeight = _initHeight;
        HorVel = _HorVel;
        initVerVel = _VerVel;
    }
}

bool MoonObject::setHeight(double _initHeight) {
    if(_initHeight > 0) { // validation
        initHeight = _initHeight;
        return true;
    }
    return false; // return false by default
}

bool MoonObject::setHorVel(double _HorVel) {
    if(_HorVel > 0) { // validation
        HorVel = _HorVel;
        return true;
    }
    return false; // return false by default
}

bool MoonObject::setVerVel(double _VerVel) {
    if(_VerVel > 0) { // validation
        initVerVel = _VerVel;
        return true;
    }
    return false; // return false by default
}
double MoonObject::getXPos(double time) {
    double retVal = HorVel * time;
    return retVal;
}

double MoonObject::getYPos(double time) {
    double retVal = initHeight + initVerVel * time - 0.5 * Gravity * time * time;
    return retVal;
}