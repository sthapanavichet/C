// Name: Sthapanavichet Long 
// Student ID: 1375802215
// email: slong17@myseneca.ca
//AnalogCircuit.cpp - simulator for an analog circuit with a resistor,
//                    inductor and capacitor placed in parallel.

#define _USE_MATH_DEFINES
#include <fstream>
#include <iomanip>
#include <math.h>
#include <iostream>
#include "Resistor.h"//this assumes the class for the resistor is in Resistor.h
#include "Inductor.h"//this assumes the class for the inductor is in Inductor.h
#include "Capacitor.h"//this assumes the class for the capacitor is in Capacitor.h

using namespace std;

int main(void) {
	//The following assume that the classes for the inductor, capacitor and resistor
	//are called Inductor, Capacitor, and Resistor
	Inductor inductor(0.01);//inductance of 0.01H
	Capacitor capacitor(0.0001);//capacitance of 0.0001F
	Resistor resistor(10.0);//resistance of 10ohms
	const double delta = 0.0001;//timestep of 0.0001 seconds
	const double frequency = 50.0;//the applied voltage has a frequency of 50Hz
    ofstream fout("RLC.dat");


    //Insert the file header here
	fout.setf(ios::fixed);
	fout.precision(4);
	fout << setw(10) << "Time" << setw(10) << "Voltage" << setw(10) << "Inductor" << setw(10) << "Capacitor" << setw(10) << "Resistor" << setw(10) << "Total" << endl;
	for (double time = 0.0; time < 0.1; time += delta) {//the simulation runs for 0.1 seconds
		double voltage = 100 * sin(2 * M_PI * frequency * time);//the applied voltage
		double currentInductor = inductor.GetCurrent(voltage, delta);//the current through the inductor
		double currentCapacitor = capacitor.GetCurrent(voltage, delta);//the current through the capacitor
		double currentResistor = resistor.GetCurrent(voltage);//the current through the resistor
		double totalCurrent = currentInductor + currentCapacitor + currentResistor;//the total current
        //Print the results to the file her
		fout << setw(10) << time << setw(10) << voltage << setw(10) << currentInductor << setw(10) << currentCapacitor << setw(10) << currentResistor << setw(10) << totalCurrent << endl; 
	}
	fout.close();
	//Clean up here
	return 0;
}