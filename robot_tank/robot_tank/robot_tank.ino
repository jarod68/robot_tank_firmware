// 
// robot_tank 
//
// Description of the project
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author	 	Matt
// 				Matthieu Holtz
//
// Date			17/09/2014 15:32
// Version		<#version#>
// 
// Copyright	© Matt, 2014
// License		<#license#>
//
// See			ReadMe.txt for references
//

#include <Arduino.h>
#include <Makeblock.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include "Tank.h"
#include "AutoTankState.h";


Tank tank (M1, M2, PORT_3, PORT_4);
AutoTankState autoTankState(&tank);


void setup() {
  
    randomSeed(analogRead(PORT0));
    Serial.begin(9600);
    tank.setCurrentState(&autoTankState);
}

void loop() {
    tank.onLoop();
}
