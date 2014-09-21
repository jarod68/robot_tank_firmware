
#include "TankState.h"


TankState::TankState(Tank * tank):
    _tank(tank)
{
    
}
TankState::~TankState()
{
    
}


Tank * TankState::getTank() const
{
    return _tank;
}