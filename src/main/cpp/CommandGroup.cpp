#include "CommandGroup.h"

void CommandGroup::InitAutoCommands(){}

void CommandGroup::InitCommands(){

    RobotDrive.DriveInit();
    RobotArm.ArmInit();
    RobotClaw.ClawInit();

    safeLock = 1;
    estadoCompressor = 0;

}

void CommandGroup::PeriodicCommands(){                                   

    RobotDrive.Drive(pilotStick.GetY(), pilotStick.GetZ(), safeLock);
    RobotArm.ArmPeriodic(safeLock, operatorStick.GetY());
    
} 

void CommandGroup::PilotCommands(){

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){
        
        safeLock = !safeLock;
        
    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRB)){

        RobotDrive.DriveSpeedChange(1, 0.1);
    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLB)){

        RobotDrive.DriveSpeedChange(-1, 0.1);

    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonRT)){

        RobotDrive.DriveSpeedMax();
    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLB)){

        RobotDrive.DriveSpeedStandard();

    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonY)){

        RobotDrive.DriveDirection();

    }

}

void CommandGroup::OperatorCommands(){
    
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){
        
        safeLock = !safeLock;
        
    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonB) && safeLock == 1){

        if(estadoCompressor == 0){

            RobotClaw.EnableCompressor();
            estadoCompressor = 1;

       } else {

            RobotClaw.DisableCompressor();
            estadoCompressor = 0;

       }

    }else if(safeLock == 0 && estadoCompressor == 1){

        RobotClaw.DisableCompressor();
        estadoCompressor = 0;

    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonX) && safeLock == 1){

        RobotClaw.AtivaSolenoide();

    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonSTART)){

        RobotArm.armControlDirection = 0;

    } 

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonY)){

        RobotArm.ArmSwitchUp();
    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonA)){

        RobotArm.ArmSwitchDown();

    }

    if(operatorStick.GetRawButton(JoystickConstants::buttonRB)){

        RobotClaw.ClawSlideForward(safeLock, ClawConstants::forwardSlidePercent);

    }else if(operatorStick.GetRawButton(JoystickConstants::buttonLB)){

        RobotClaw.ClawSlideReturn(safeLock, ClawConstants::returnSlidePercent);

    }else {

        RobotClaw.ClawStop();

    }

}

void CommandGroup::Log(){

    RobotDrive.DriveLog();
    RobotArm.ArmLog();
    RobotClaw.ClawLog();

}