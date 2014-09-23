#pragma once

#ifndef TANK_H
#define TANK_H


#include <Arduino.h>
#include <Makeblock.h>

#include "TankState.h"

#define DEFAULT_LINE_SPEED 200
#define DEFAULT_TURN_SPEED 200

class TankState;

enum TankMove {
    Forward,
    Backward,
    Left,
    Right,
    Stop
};

class Tank
{
    
    
public:
    Tank (uint8_t rightMotorPort, uint8_t leftMotorPort, uint8_t ultraSonicSensorPort, uint8_t irReceiverPOrt);
    virtual ~Tank ();
    
    virtual TankState * getCurrentState() const;
    virtual void setCurrentState(TankState * state);
    
    virtual void onLoop();
    
    virtual void forward(uint8_t speed);
    virtual void forward() ;

    virtual void backward(uint8_t speed);
    virtual void backward() ;

    virtual void left() ;
    virtual void right() ;
    
    virtual void stop() ;

    virtual void setTurnSpeed(uint8_t turnSpeed);
    virtual void setLineSpeed(uint8_t lineSpeed);
    
    virtual uint8_t getTurnSpeed() const;
    virtual uint8_t getLineSpeed() const;
    
    virtual TankMove getCurrentMove() const;
    
    virtual long distanceCm()const;
    
private:
    MeDCMotor * _rightMotor;
    MeDCMotor * _leftMotor;
    MeUltrasonicSensor * _ultraSonicSensor;
    MeInfraredReceiver * _irReceiver;
    TankState * _currentState;
    uint8_t _turnSpeed;
    uint8_t _lineSpeed;
    TankMove _currentMove;

};


#endif