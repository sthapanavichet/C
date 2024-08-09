// Name: Sthapanavichet Long 
// Student ID: 1375802215
// email: slong17@myseneca.ca
#include "Resistor.h"
#include "inductor.h"
#include "Capacitor.h"
#include <iostream>

using namespace std;
Inductor::Inductor(double _inductance) {
    if(_inductance > 0) {
        inductance = _inductance;
    }
    else {
        inductance = 0;
        cout << "Invalid Inductance Given" << endl;
    }
    current = 0;
}

double Inductor::GetCurrent(double voltage, double timeStep) {
    current += voltage * timeStep / inductance;
    return current;
}

Capacitor::Capacitor(double _capacitance) {
    if(_capacitance > 0) {
        capacitance = _capacitance;
    }
    else {
        capacitance = 0;
        cout << "Invalid Capacitance Given" << endl;
    }
    voltage = 0;
    current = 0;
}

double Capacitor::GetCurrent(double _voltage, double timeStep) {
    current = capacitance * (_voltage - voltage) / timeStep;
    voltage = _voltage; 
    return current;
}

Resistor::Resistor(double _resistance) {
    if(_resistance > 0) {
        resistance = _resistance;
    }
    else {
        resistance = 0;
        cout << "Invalid Resistance Given" << endl;
    }
}

double Resistor::GetCurrent(double voltage) {
    return voltage / resistance;
}


