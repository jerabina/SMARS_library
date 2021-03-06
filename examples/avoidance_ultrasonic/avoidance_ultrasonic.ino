/*
--------------------------------------------------------------------------------
SMARS robot firmware
(Screwless/Screwed Modular Assemblable Robotic System)
url: https://www.thingiverse.com/thing:2662828
--------------------------------------------------------------------------------
The robot detects the distance of objects by sonar 
and if less than 15 cm turns left and continues its journey

You need to have libraries installed: Servo, NewPing
--------------------------------------------------------------------------------
(c) 2019 - Lubos Jerabek <robotika@lubosjerabek.cz>
--------------------------------------------------------------------------------
*/

#include "Smars.h"

Smars robot; 
unsigned long sonarDistance;
int speed = 200;

void setup() {
	robot.beepSuccess();
	robot.led(0, 255, 0);
}

void loop() {
	sonarDistance = robot.sonar();

	if (sonarDistance>0 && sonarDistance<15) {
		robot.led(255, 0, 0);
		robot.motorsStop();
		robot.beepDanger();
		delay(10);
		robot.led(255, 255, 0);
		robot.motorsBack(speed);
		delay(400);
		robot.motorsLeft(speed);
		delay(600);
		robot.motorsStop();
		
	} else {
		robot.led(0, 255, 0);
		robot.motorsForward(speed);
	}
	delay(100);
}