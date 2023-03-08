#include "Arm.h"

void Arm::ArmLog(){

    frc::SmartDashboard::PutNumber("OperatorStickValue", operatorStickValue);
    frc::SmartDashboard::PutNumber("topLimitSwitch", topLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("bottomLimitSwitch", bottomLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("ArmRedLine", ArmRedLine.GetBusVoltage());

}

void Arm::ArmFeed(bool lock, double percent){

    if(percent > ArmConstants::operatorArmDeadBand || percent < -1*ArmConstants::operatorArmDeadBand){

        operatorStickValue = -1*percent*lock*ArmConstants::armPercentConstrain; //se o motor estiver invertido *-1
             
    }else {

        //operatorStickValue = ArmConstants::amrKeepUp;
        operatorStickValue = 0;

    }

    if(topLimitSwitch.Get()){

        operatorStickValue = abs(operatorStickValue);

    }else if(bottomLimitSwitch.Get()){

        operatorStickValue = -abs(operatorStickValue);

    }

    ArmRedLine.Set(ControlMode::PercentOutput, operatorStickValue);
    
}

void Arm::ArmInit(){

    ArmRedLine.SetNeutralMode(NeutralMode::Brake);
    ArmRedLine.ConfigOpenloopRamp(0.1); 

    ArmRedLine.SetSafetyEnabled(true);
    ArmRedLine.SetExpiration(100_ms);

}
