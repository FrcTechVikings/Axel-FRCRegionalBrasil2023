#include "Claw.h"

void Claw::ClawLog(){

    frc::SmartDashboard::PutBoolean("Estado do Compressor", comp.IsEnabled());
    frc::SmartDashboard::PutNumber("frontLimitSwitch", frontLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("rearLimitSwitch", rearLimitSwitch.Get());
    frc::SmartDashboard::PutNumber("Solenoide", solenoid.Get());
    frc::SmartDashboard::PutNumber("Snow Esquerda", ClawSlowLeft.GetBusVoltage());
    frc::SmartDashboard::PutNumber("Snow Direta", ClawSlowRight.GetBusVoltage());

}

void Claw::ClawSlideForward(bool lock, double percent){

     /*if(frontLimitSwitch.Get() == false){

        ClawSlowLeft.Set(ControlMode::PercentOutput, -1*percent*lock);
        ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);  
         
    }else {

        ClawSlowLeft.Set(ControlMode::PercentOutput, 0);
        ClawSlowRight.Set(ControlMode::PercentOutput, 0);

    }*/

    ClawSlowLeft.Set(ControlMode::PercentOutput, percent*lock);
    ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);  
}

void Claw::ClawSlideReturn(bool lock, double percent){

    if(rearLimitSwitch.Get() == false){

        ClawSlowLeft.Set(ControlMode::PercentOutput, -1*percent*lock);
        ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);  
         
    }else {

        ClawSlowLeft.Set(ControlMode::PercentOutput, 0);
        ClawSlowRight.Set(ControlMode::PercentOutput, 0);

    }

    //ClawSlowLeft.Set(ControlMode::PercentOutput, percent*lock);
    //ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);  

}

void Claw::ClawStop(){

    ClawSlowLeft.Set(ControlMode::PercentOutput, 0);
    ClawSlowRight.Set(ControlMode::PercentOutput, 0);
}

void Claw::ClawInit(){

    ClawSlowRight.SetNeutralMode(NeutralMode::Brake);
    ClawSlowLeft.SetNeutralMode(NeutralMode::Brake);

    solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    comp.EnableDigital();

    ClawSlowRight.SetSafetyEnabled(true);
    ClawSlowRight.SetExpiration(100_ms);

    ClawSlowLeft.SetSafetyEnabled(true);
    ClawSlowLeft.SetExpiration(100_ms);

}

void Claw::EnableCompressor(){

    comp.EnableDigital();

}

void Claw::DisableCompressor(){

    comp.Disable();

}

void Claw::AtivarSolenoide(){

    solenoid.Toggle();
    
}