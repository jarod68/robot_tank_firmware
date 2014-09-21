#pragma once

#ifndef PARKINGTANKSTATE_H
#define PARKINGTANKSTATE_H

#include "TankState.h"
#include "Tank.h"

class ParkingTankState : public TankState
{
public:
    ParkingTankState(Tank * tank);
    virtual ~ParkingTankState();
    
public:
    virtual void onLoop();
    virtual void onKeyPress();
    

};

#endif
