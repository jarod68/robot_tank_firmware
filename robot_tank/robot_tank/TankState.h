#pragma once

#ifndef TANKSTATE_H
#define TANKSTATE_H

#include "Tank.h"

class Tank;

class TankState
{
    
public:
    
    TankState(Tank * tank);
    virtual ~TankState();
    
    virtual void onLoop() = 0;
    virtual void onKeyPress() = 0;
    
protected:
    Tank * getTank() const;
    
private:
    Tank * _tank;
    
};

#endif