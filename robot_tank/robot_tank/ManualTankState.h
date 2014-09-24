
#pragma once

#ifndef MANUALTANKSTATE_H
#define MANUALTANKSTATE_H

#include "TankState.h"
#include "Tank.h"

#define DEFAULT_BASE_SPEED 100


class ManualTankState : public TankState
{
public:
    ManualTankState(Tank * tank);
    virtual ~ManualTankState();
    
public:
    virtual void onLoop();
    virtual void onKeyPress(uint16_t keyCode);
    
private:
    
    uint16_t _baseSpeed;
};

#endif