//ObjectMain.cpp - main program for moving objects on the moon and on earth

// 18-Mar-21  M. Watler         Created.

#include <iostream>
#include "MoonObject.h"
#include "EarthObject.h"

using namespace std;

int main(void) {
	double initialHeightEarth = 100;
	double horizontalSpeedEarth = 100;
	double initialHeightMoon = 100;
	double initialVerticalSpeedMoon = 10;
	double horizontalSpeedMoon = 100;

	MoonObject moon(initialHeightMoon, initialVerticalSpeedMoon, horizontalSpeedMoon);
	EarthObject earth(initialHeightEarth, horizontalSpeedEarth);
	double time;
	for (time = 0.0; moon.getYPos(time) > 0 && earth.getYPos(time) > 0; time += 0.001) {}

	cout << "time:" << time << endl;
	cout << "The moon object's horizontal position is " << moon.getXPos(time) << "m and vertical position is " << moon.getYPos(time) << "m" << endl;
	cout << "The earth object's horizontal position is " << earth.getXPos(time) << "m and vertical position is " << earth.getYPos(time) << "m" << endl << endl;

	bool valid;

	//TODO: Prompt the user to enter new parameters for the moon object and the earth object.
	//      For the moon, the parameters are: initial height, initial vertical speed, and the horizontal speed.
	//      For the earth, the parameters are: initial height and the horizontal speed.
	//Be sure to perform validation on the entered values.
     // input and validation
	do {
        cout << "Enter the moon object's horizontal speed: ";
        cin >> horizontalSpeedMoon;
        valid = moon.setHorVel(horizontalSpeedMoon);
        if(cin.fail() == true || valid == false) { // validation
            cout << "invalid value" << endl;
        }
    } while(valid == false);

    do {
        cout << "Enter the moon object's initial vertical speed: ";
        cin >> initialVerticalSpeedMoon;
        valid = moon.setVerVel(initialVerticalSpeedMoon);
        if(cin.fail() == true || valid == false) { // validation
            cout << "invalid value" << endl;
        }
    } while(valid == false);
    
    
    do {
        cout << "Enter the moon object's initial height: ";
        cin >> initialHeightMoon;
        valid = moon.setHeight(initialHeightMoon);
        if(cin.fail() == true || valid == false) { // validation
            cout << "invalid value" << endl;
        }
    } while(valid == false);

    do {
        cout << "Enter the earth object's horizontal speed: ";
        cin  >> horizontalSpeedEarth;
        valid = earth.setHorVel(horizontalSpeedEarth);
        if(cin.fail() == true || valid == false) { // validation
            cout << "invalid value" << endl;
        }
    } while(valid == false);

    do {
        cout << "Enter the earth object's initial height: ";
        cin >> initialHeightEarth;
        valid = earth.setHeight(initialHeightEarth);
        if(cin.fail() == true || valid == false) { // validation
            cout << "invalid value" << endl;
        }
    } while(valid == false);

	//The simulation runs again
	for (time = 0.0; moon.getYPos(time) > 0 && earth.getYPos(time) > 0; time += 0.001) {}

	cout << endl;
	cout << "time:" << time << endl;
	cout << "The moon object's horizontal position is " << moon.getXPos(time) << "m and vertical position is " << moon.getYPos(time) << "m" << endl;
	cout << "The earth object's horizontal position is " << earth.getXPos(time) << "m and vertical position is " << earth.getYPos(time) << "m" << endl;

	return 0;
}