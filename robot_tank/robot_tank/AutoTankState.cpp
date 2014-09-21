#include "AutoTankState.h"


AutoTankState::AutoTankState(Tank * tank) : TankState(tank)
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
    
    if(distance <= 20){
        tank->right();
    }
    else{
        tank->forward();
    }
    
    
}
void AutoTankState::onKeyPress()
{
    
}
