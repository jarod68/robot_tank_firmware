
#pragma once

#ifndef AUTOTANKSTATE_H
#define AUTOTANKSTATE_H

#include "TankState.h"
#include "Tank.h"

#define DEFAULT_MAX_SPEED 100
#define DEFAULT_MIN_SPEED 200
#define DEFAULT_SECURITY_DISTANCE 37


class AutoTankState : public TankState
{
public:
    AutoTankState(Tank * tank);
    virtual ~AutoTankState();
    
public:
    virtual void onLoop();
    virtual void onKeyPress();
    
    virtual void setMaxSpeed(uint16_t max);
    virtual void setMinSpeed(uint16_t min);
    
    virtual uint16_t getMaxSpeed() const;
    virtual uint16_t getMinSpeed() const;
    virtual uint16_t getSecurityDistance() const;

    
private:
    uint16_t _maxSpeed;
    uint16_t _minSpeed;
    uint16_t _securityDistance;
    bool _isTurning;
};

#endif
