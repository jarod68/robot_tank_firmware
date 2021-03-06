#include "Tank.h"
#include "ParkingTankState.h"
#include "ManualTankState.h"
#include "AutoTankState.h"

    Tank    ::  Tank (uint8_t rightMotorPort,
                      uint8_t leftMotorPort,
                      uint8_t ultraSonicSensorPort,
                      uint8_t irReceiverPOrt
                      ) :
                        _rightMotor(new MeDCMotor (rightMotorPort)),
                        _leftMotor(new MeDCMotor (leftMotorPort)),
                        _ultraSonicSensor(new MeUltrasonicSensor(ultraSonicSensorPort)),
                        _currentState(NULL),
                        _parkingState(NULL),
                        _autoState(NULL),
                        _manualState(NULL),
                        _turnSpeed(DEFAULT_TURN_SPEED),
                        _lineSpeed(DEFAULT_LINE_SPEED),
                        _irReceiver(new MeInfraredReceiver(irReceiverPOrt)),
                        _currentMove(Stop),
                        _buzzerMode(None)
{
    // Unsafe to use this in initializer list
    _parkingState   = new ParkingTankState  (this);
    _manualState    = new ManualTankState   (this);
    _autoState      = new AutoTankState     (this);
    
    setMode(Parking);
    _irReceiver->begin(); //start infrared receiver
}

    Tank    ::  ~Tank ()
{
    delete _rightMotor;
    delete _leftMotor;
    delete _ultraSonicSensor;
    delete _irReceiver;
}

TankState *     Tank    ::  getCurrentState () const
{
    return _currentState;
}

void            Tank    ::  setCurrentState (TankState * state)
{
    if(state == NULL)
        return;
    
    _currentState = state;
}

void            Tank    ::  onLoop          ()
{
    if (_currentState == NULL)
        return;
    
    if(_irReceiver->available())
        _currentState->onKeyPress(_irReceiver->read());
        
    _currentState->onLoop();
    
    delayMicroseconds(1);
}

void           Tank    ::  forward         (uint8_t speed)
{
    this->setLineSpeed(speed);
    this->forward();
}

void           Tank    ::  forward         ()
{
    _leftMotor->run(+_lineSpeed);
    _rightMotor->run(+_lineSpeed);
    _currentMove = Forward;
}

void           Tank     ::  backward           (uint8_t speed)
{
    this->setLineSpeed(speed);
    this->backward();
}

 void           Tank    ::  backward    ()
{
    _leftMotor->run(- _lineSpeed);
    _rightMotor->run(- _lineSpeed);
    _currentMove = Backward;
}

void            Tank    ::  left        ()
{
    _leftMotor->run(- _turnSpeed);
    _rightMotor->run(+_turnSpeed);
    _currentMove = Left;
}
void            Tank    ::  right       ()
{
    _leftMotor->run(+_turnSpeed);
    _rightMotor->run(-_turnSpeed);
    _currentMove = Right;
}

void            Tank    ::  stop        ()
{
    _leftMotor->stop();
    _rightMotor->stop();
    _currentMove = Stop;
}

 void           Tank    ::  setTurnSpeed    (uint8_t turnSpeed)
{
    _turnSpeed = turnSpeed;
}

 void           Tank    ::  setLineSpeed    (uint8_t lineSpeed)
{
    _lineSpeed = lineSpeed;
}

 uint8_t        Tank    ::  getTurnSpeed    () const
{
    return _turnSpeed;
}

 uint8_t        Tank    ::  getLineSpeed    () const
{
    return _lineSpeed;
}

long            Tank    ::  distanceCm      () const
{
    return _ultraSonicSensor->distanceCm();
}

TankMove        Tank    ::  getCurrentMove  () const
{
    return _currentMove;
}

 TankMode       Tank    ::  getCurrentMode  () const
{
    return _currentMode;
}

void           Tank     ::  setMode         (TankMode mode)
{
    _currentMode = mode;
    stop();
    setBuzzerMode(None);
    switch (mode) {
        case Auto   : setCurrentState(_autoState);      break;
        case Manual : setCurrentState(_manualState);    break;
        case Parking: setCurrentState(_parkingState);   break;
        default     : break;
    }
    
}

BuzzerMode      Tank    ::  getBuzzerMode   () const
{
    return _buzzerMode;
}

void            Tank    ::  setBuzzerMode   (BuzzerMode mode)
{
    _buzzerMode = mode;
    
    switch (mode) {
        case None       : buzzerOff(); break;
        case Continue   : buzzerOff(); break;
        default         : break;
    }
    
}

