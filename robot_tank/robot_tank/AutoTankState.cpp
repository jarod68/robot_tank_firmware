#include "AutoTankState.h"


AutoTankState::AutoTankState(Tank * tank) : TankState(tank), _maxSpeed(DEFAULT_MAX_SPEED), _minSpeed(DEFAULT_MIN_SPEED), _securityDistance(DEFAULT_SECURITY_DISTANCE), _isTurning(false), _turnsCount(0), _previousDistance(1000)
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
        
        
        if(isBlocked(distance)){
            _turnsCount = 0; //reset the counter
            tank->backward(_minSpeed);
            delay(750);
        }else if(!_isTurning){
            
            if(random(2) == 0)
                tank->right();
            else
                tank->left();
            
            _isTurning = true;
            _turnsCount++;
        }
        
    }
    else{
        
        if(distance > _securityDistance * 2)
            tank->forward(_maxSpeed);
        else
            tank->forward(_minSpeed);
        
         _isTurning = false;
        
    }
    
     handleBlockDetection(distance);
}

void AutoTankState::handleBlockDetection(long currentDistance){
  
    _previousDistance = currentDistance;
    _blockCount++;
    
    
}

bool AutoTankState::isBlocked(long currentDistance)
{
    long delta = max(currentDistance, _previousDistance) - min(currentDistance, _previousDistance);
    
    if(_blockCount >= 10000 && delta  < 3){
        _blockCount=0;
        return true;
    }
    
    return false;
}

void AutoTankState::onKeyPress(uint16_t keyCode)
{
    Tank * tank =  getTank();
    
    if(tank == NULL)
        return;
    
    switch(keyCode)
    {
        case IR_BUTTON_B: tank->setMode(Manual); break;
        default:break;
    }
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
