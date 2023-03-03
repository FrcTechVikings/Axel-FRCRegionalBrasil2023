#include "Arm.h"

void Arm::ArmLog(){}

void Arm::ArmFeed(bool lock, double percent){

    if(percent > ArmConstants::operatorArmDeadBand || percent < -1*ArmConstants::operatorArmDeadBand){

        operatorStickValue = percent*lock*ArmConstants::armPercentConstrain; //se o motor estiver invertido *-1
             
    }else {

        operatorStickValue = ArmConstants::amrKeepUp;

    }

    ArmRedLine.Set(ControlMode::PercentOutput, operatorStickValue);
    
}

void Arm::ArmSwitchUp(){

    armControlDirection = 1;

}

void Arm::ArmSwitchDown(){

    armControlDirection = -1;

}

void Arm::ArmPeriodic(bool lock, double JoyAxisY){

    if(lock == 0){

        armControlDirection = 0;

    } 

    if(armControlDirection == 1){

        ArmRedLine.Set(ControlMode::PercentOutput, ArmConstants::armPercentUp);
        if(topLimitSwitch.Get()){

            armControlDirection = 0;
            
        }

    }else if (armControlDirection == -1){

        ArmRedLine.Set(ControlMode::PercentOutput, ArmConstants::armPercentDown);
        if(bottomLimitSwitch.Get()){

            armControlDirection = 0;

        }

    }else if (armControlDirection == 0){

        ArmFeed(lock, JoyAxisY);

    }
}

void Arm::ArmInit(){

    ArmRedLine.SetNeutralMode(NeutralMode::Brake);
    ArmRedLine.ConfigOpenloopRamp(0.1); 

    ArmRedLine.SetSafetyEnabled(true);
    ArmRedLine.SetExpiration(100_ms);

    armControlDirection = 0;

}
