#include "ManualTankState.h"


ManualTankState::ManualTankState(Tank * tank) : TankState(tank)
{
    
}
ManualTankState::~ManualTankState()
{
    
}

void ManualTankState::onLoop()
{
    Tank * tank =  getTank();
    
    if(tank == NULL)
        return;
    
}


void ManualTankState::onKeyPress(uint16_t keyCode)
{
    Tank * tank =  getTank();
    
    if(tank == NULL)
        return;

    switch(keyCode)
    {
        case IR_BUTTON_A: break;
        case IR_BUTTON_B: break;
        case IR_BUTTON_C: break;
        case IR_BUTTON_D: break;
        case IR_BUTTON_E: break;
        case IR_BUTTON_F: break;
        case IR_BUTTON_SETTING: tank->stop(); break;
        case IR_BUTTON_UP: tank->forward(); break;
        case IR_BUTTON_DOWN: tank->backward(); break;
        case IR_BUTTON_LEFT: tank->left(); break;
        case IR_BUTTON_RIGHT: tank->right(); break;
        case IR_BUTTON_0: break;
        case IR_BUTTON_1: break;
        case IR_BUTTON_2: break;
        case IR_BUTTON_3: break;
        case IR_BUTTON_4: break;
        case IR_BUTTON_5: break;
        case IR_BUTTON_6: break;
        case IR_BUTTON_7: break;
        case IR_BUTTON_8: break;
        case IR_BUTTON_9: break;
        default:break;
    }
    
}
