#include "ParkingTankState.h"


ParkingTankState::ParkingTankState(Tank * tank) : TankState(tank)
{
    
}
 ParkingTankState::~ParkingTankState()
{
    
}

 void ParkingTankState::onLoop()
{
    
}
 void ParkingTankState::onKeyPress(uint16_t keyCode)
{
    Tank * tank =  getTank();
    
    if(tank == NULL)
        return;
    
    switch(keyCode)
    {
        case IR_BUTTON_A: tank->setMode(Auto); break;
        case IR_BUTTON_B: tank->setMode(Manual); break;
        default:break;
    }
}
