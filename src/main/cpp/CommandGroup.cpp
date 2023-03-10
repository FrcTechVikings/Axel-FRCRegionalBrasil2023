#include "CommandGroup.h"

void CommandGroup::InitAutoCommands(){

    RobotDrive.frontLeft.SetNeutralMode(NeutralMode::Brake);
    RobotDrive.frontRight.SetNeutralMode(NeutralMode::Brake);
    RobotDrive.rearLeft.SetNeutralMode(NeutralMode::Brake);
    RobotDrive.rearRight.SetNeutralMode(NeutralMode::Brake);

    RobotDrive.ResetEnconder();

    executeOnce = 0;
    
    autoTimer.Reset();
    autoTimer.Start();

}

void CommandGroup::AutoPrincipal(double delay_s, double distPontuacao_m, double distSaida_m){

    RobotClaw.ClawSlowLeft.Set(ControlMode::PercentOutput, 0.0);
    RobotClaw.ClawSlowRight.Set(ControlMode::PercentOutput, 0.0);

    if(autoTimer.Get().value() <= AutoConstants::configInicial + delay_s){

        RobotArm.ArmFeed(1, 0.0);
        RobotDrive.Drive(0.0, 0.0, 1);
        
    } else if (autoTimer.Get().value() <= AutoConstants::initialDriveForward + delay_s){

        RobotArm.ArmFeed(1, 0.0);

        if(RobotDrive.GetDistanceEncoder() <= distPontuacao_m){

            RobotDrive.Drive(-0.6, 0.0, 1);

        } else {

            RobotDrive.Drive(0.0, 0.0, 1);

        }

    } else if (autoTimer.Get().value() <= AutoConstants::lowerArm + delay_s){

        RobotDrive.ResetEnconder();
        RobotArm.ArmFeed(1, 1);
        RobotDrive.Drive(0.0, 0.0, 1);

    } else if(autoTimer.Get().value() <= AutoConstants::releaseGamePiece + delay_s){

        RobotArm.ArmFeed(1, 0.0);
        RobotDrive.Drive(0.0, 0.0, 1);
        if(executeOnce == 0){

            RobotClaw.AtivarSolenoide();
            executeOnce = 1;

        }

    } else if (autoTimer.Get().value() <= AutoConstants::higherArm + delay_s){

        RobotArm.ArmFeed(1, -1);
        RobotDrive.Drive(0.0 , 0.0, 1);

    } else if (autoTimer.Get().value() <= AutoConstants::returnBack + delay_s){

        RobotArm.ArmFeed(1, 0.0);
        
        if(RobotDrive.GetDistanceEncoder() <= distSaida_m){

            RobotDrive.Drive(0.9, 0.0, 1);

        } else {

            RobotDrive.Drive(0.0, 0.0, 1);

        }

    } else {

        RobotArm.ArmFeed(1, 0.0);
        RobotDrive.Drive(0.0, 0.0, 1);

    }

}

void CommandGroup::AutoNothing(){

    RobotArm.ArmFeed(1, 0.0);
    RobotDrive.Drive(0.0, 0.0, 1);
    RobotClaw.ClawSlowLeft.Set(ControlMode::PercentOutput, 0.0);
    RobotClaw.ClawSlowRight.Set(ControlMode::PercentOutput, 0.0);

}

void CommandGroup::InitCommands(){

    RobotDrive.DriveInit();
    RobotArm.ArmInit();
    RobotClaw.ClawInit();

    safeLock = 1;
    estadoCompressor = 1;

    frc::SmartDashboard::PutNumber("Distância Para Pontuação (metros)", 2.0);
    frc::SmartDashboard::PutNumber("Distância de Retorno (metros)", 5.0);
    frc::SmartDashboard::PutNumber("Delay (segundos)", 0.2);

}

void CommandGroup::PeriodicCommands(){                                   

    RobotDrive.Drive(pilotStick.GetY(), pilotStick.GetZ(), safeLock);
    RobotArm.ArmFeed(safeLock, operatorStick.GetY());
    
} 

void CommandGroup::PilotCommands(){

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){
        
        safeLock = !safeLock;

        if(safeLock == 1){

            RobotClaw.EnableCompressor();

        }
        
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

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonLT)){

        RobotDrive.DriveSpeedStandard();

    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonY)){

        RobotDrive.DriveDirection();

    }

    if(pilotStick.GetRawButtonPressed(JoystickConstants::buttonB)){

        RobotDrive.DriveSlowTurn();

    }

}

void CommandGroup::OperatorCommands(){
    
    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonBACK)){
        
        safeLock = !safeLock;

        if(safeLock == 1){

            RobotClaw.EnableCompressor();

        }
        
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

        RobotClaw.AtivarSolenoide();

    }

    if(operatorStick.GetRawButton(JoystickConstants::buttonRT)){

        RobotClaw.ClawSlideForward(safeLock, ClawConstants::forwardSlidePercent);

    }else if(operatorStick.GetRawButton(JoystickConstants::buttonLT)){

        RobotClaw.ClawSlideReturn(safeLock, ClawConstants::returnSlidePercent);

    }else {

        RobotClaw.ClawStop();

    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonY) && safeLock == 1){

        RobotArm.ArmMaxSpeed();

    }

    if(operatorStick.GetRawButtonPressed(JoystickConstants::buttonA) && safeLock == 1){

        RobotArm.ArmStandardSpeed();

    }

}

void CommandGroup::Log(){

    RobotDrive.DriveLog();
    RobotArm.ArmLog();
    RobotClaw.ClawLog();

    frc::SmartDashboard::PutNumber("Piloto JoyY", pilotStick.GetY());
    frc::SmartDashboard::PutNumber("Piloto JoyZ", pilotStick.GetZ());
    frc::SmartDashboard::PutNumber("Operador JoyY", operatorStick.GetY());

    frc::SmartDashboard::PutBoolean("SafeLock", safeLock);

}

void CommandGroup::Teste(){

    PeriodicCommands();

}