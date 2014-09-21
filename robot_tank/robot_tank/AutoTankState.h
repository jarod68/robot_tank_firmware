
#pragma once

#ifndef AUTOTANKSTATE_H
#define AUTOTANKSTATE_H

#include "TankState.h"
#include "Tank.h"

class AutoTankState : public TankState
{
public:
    AutoTankState(Tank * tank);
    virtual ~AutoTankState();
    
public:
    virtual void onLoop();
    virtual void onKeyPress();
    
    
};

#endif
