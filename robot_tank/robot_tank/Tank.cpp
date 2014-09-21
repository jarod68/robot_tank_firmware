#include "Tank.h"
#include "ParkingTankState.h"

Tank::Tank (uint8_t rightMotorPort, uint8_t leftMotorPort, uint8_t ultraSonicSensorPort) :
_rightMotor(new MeDCMotor (rightMotorPort)), _leftMotor(new MeDCMotor (leftMotorPort)), _ultraSonicSensor(new MeUltrasonicSensor(ultraSonicSensorPort)), _currentState(NULL), _turnSpeed(DEFAULT_TURN_SPEED), _lineSpeed(DEFAULT_LINE_SPEED)
{
    setCurrentState(new ParkingTankState(this));// we do that here because this is not initialized in the initilization part
}
 Tank::~Tank ()
{
    delete _rightMotor;
    delete _leftMotor;
    delete _ultraSonicSensor;
}

 TankState * Tank::getCurrentState() const
{
    return _currentState;
}
 void Tank::setCurrentState(TankState * state)
{
    if(state == NULL)
        return;
    
    _currentState = state;
}

 void Tank::onLoop()
{
    _currentState->onLoop();
    
}

 void Tank::forward(uint8_t speed)
{
    this->setLineSpeed(speed);
    this->forward();
}
 void Tank::forward() const
{
    _leftMotor->run(+_lineSpeed);
    _rightMotor->run(+_lineSpeed);
}

 void Tank::backward(uint8_t speed)
{
    this->setLineSpeed(speed);
    this->backward();
}
 void Tank::backward() const
{
    _leftMotor->run(- _lineSpeed);
    _rightMotor->run(- _lineSpeed);
}

 void Tank::left() const
{
    _leftMotor->run(- _turnSpeed);
    _rightMotor->run(+_turnSpeed);
}
 void Tank::right() const
{
    _leftMotor->run(+_turnSpeed);
    _rightMotor->run(-_turnSpeed);
}

void Tank::stop() const
{
    _leftMotor->stop();
    _rightMotor->stop();
}

 void Tank::setTurnSpeed(uint8_t turnSpeed)
{
    _turnSpeed = turnSpeed;
}
 void Tank::setLineSpeed(uint8_t lineSpeed)
{
    _lineSpeed = lineSpeed;
}

 uint8_t Tank::getTurnSpeed() const
{
    return _turnSpeed;
}
 uint8_t Tank::getLineSpeed() const
{
    return _lineSpeed;
}

long Tank::distanceCm()const
{
    return _ultraSonicSensor->distanceCm();
}
