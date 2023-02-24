#include "CommandGroup.h"

void CommandGroup::InitAutoCommands(){}

void CommandGroup::InitCommands(){

    RobotDrive.DriveInit();
    RobotPneumatic.Init();

    safeLock = 1;
    estadoCompressor = 0;

}

void CommandGroup::PeriodicCommands(){} //a cada segundo

void CommandGroup::PilotCommands(){

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){
        
        safeLock = !safeLock;
        
    }

}

void CommandGroup::OperatorCommands(){
    
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){
        
        safeLock = !safeLock;
        
    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonB) && safeLock == 1){

        if(estadoCompressor == 0){

            RobotPneumatic.EnableCompressor();
            estadoCompressor = 1;

       } else {

            RobotPneumatic.DisableCompressor();
            estadoCompressor = 0;

       }

    }else if(safeLock == 0 && estadoCompressor == 1){

        RobotPneumatic.DisableCompressor();
        estadoCompressor = 0;

    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonX) && safeLock == 1){

        RobotPneumatic.AtivaSolenoide();

    }

}

void CommandGroup::Log(){

    RobotDrive.DriveLog();
    RobotPneumatic.PneumaticLog();

}