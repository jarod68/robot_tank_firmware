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

/*

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeUltrasonicSensor ultraSonic(PORT_3);


uint8_t lineSpeed = 100;
uint8_t turnSpeed = 200;
long currentDistance;
long previousDistance;
long blockCalls = 0;
bool isTurning = false;
const uint16_t minDistance = 37;
const uint16_t highSpeedDistance = 80;


void forward(){
    motor1.run(lineSpeed);
	motor2.run(lineSpeed);

}

void backward(){
    motor1.run(-lineSpeed);
	motor2.run(-lineSpeed);

}

void left(){
    motor1.run(-turnSpeed);
	motor2.run(turnSpeed);

}

void right(){
    motor1.run(turnSpeed);
	motor2.run(-turnSpeed);

}

void stop(){
    motor1.stop();
	motor2.stop();
    
}

void handleBlockDetection(){
    
    if(blockCalls >= 30){
        previousDistance = currentDistance;
    }
    
    else
        blockCalls++;
}

bool isBlocked(){
    
    if (blockCalls >= 30 && sqrt(pow(currentDistance,2) + pow(previousDistance, 2)) <=minDistance)
        return true;
    
    return false;
}
*/

Tank tank (M1, M2, PORT_3);
AutoTankState autoTankState(&tank);

void setup() {
  
    randomSeed(analogRead(PORT0));
    Serial.begin(9600);

    
    tank.setCurrentState(&autoTankState);
}

void loop() {
    tank.onLoop();
    
   // tank.onLoop();
    /*
    currentDistance =ultraSonic.distanceCm();
    handleBlockDetection();
    
    if(isBlocked()){
        
        lineSpeed = 100;
        backward();
        delay(500);
        
    }else if(currentDistance<=minDistance ){
        
        left();
        delay(500);
    }else{
        
        if(currentDistance >=highSpeedDistance)
            lineSpeed = 200;
        else
            lineSpeed = 100;
        
        forward();
    }
    */
}
