#include "Claw.h"

void Claw::ClawLog(){}

void Claw::ClawSlideForward(bool lock, double percent){

     if(frontLimitSwitch.Get() == false){

        ClawSlowLeft.Set(ControlMode::PercentOutput, -1*percent*lock);
        ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);  
         
    }else {

        ClawSlowLeft.Set(ControlMode::PercentOutput, 0);
        ClawSlowRight.Set(ControlMode::PercentOutput, 0);

    }
}

void Claw::ClawSlideReturn(bool lock, double percent){

    if(rearLimitSwitch.Get() == false){

        ClawSlowLeft.Set(ControlMode::PercentOutput, -1*percent*lock);
        ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);  
         
    }else {

        ClawSlowLeft.Set(ControlMode::PercentOutput, 0);
        ClawSlowRight.Set(ControlMode::PercentOutput, 0);

    }
}

void Claw::ClawStop(){

    ClawSlowLeft.Set(ControlMode::PercentOutput, 0);
    ClawSlowRight.Set(ControlMode::PercentOutput, 0);
}

void Claw::ClawInit(){

    ClawSlowRight.SetNeutralMode(NeutralMode::Brake);
    ClawSlowLeft.SetNeutralMode(NeutralMode::Brake);

    ClawSlowRight.SetSafetyEnabled(true);
    ClawSlowRight.SetExpiration(100_ms);

    ClawSlowLeft.SetSafetyEnabled(true);
    ClawSlowLeft.SetExpiration(100_ms);

}