#include "AutoTankState.h"


AutoTankState::AutoTankState(Tank * tank) : TankState(tank), _maxSpeed(DEFAULT_MAX_SPEED), _minSpeed(DEFAULT_MIN_SPEED), _securityDistance(DEFAULT_SECURITY_DISTANCE), _isTurning(false)
{
    
}
AutoTankState::~AutoTankState()
{
    
}

void AutoTankState::onLoop()
{
    Tank * tank =  getTank();
    
    if(tank == NULL)
        return;
    
    long distance = tank->distanceCm();
    
    if(distance <= _securityDistance){
        
        if(!_isTurning){
            
            if(random(2) == 0)
                tank->right();
            else
                tank->left();
            
            _isTurning = true;
        }
        
    }
    else{
        
        tank->forward();
         _isTurning = false;
        
    }
    
    
}
void AutoTankState::onKeyPress()
{
    
}

void AutoTankState::setMaxSpeed(uint16_t max)
{
    _maxSpeed = max;
}

 void AutoTankState::setMinSpeed(uint16_t min)
{
    _minSpeed = min;
}

 uint16_t AutoTankState::getMaxSpeed() const
{
    return _maxSpeed;
}
 uint16_t AutoTankState::getMinSpeed() const
{
    return _minSpeed;
}

uint16_t AutoTankState::getSecurityDistance() const
{
    return _securityDistance;
}
