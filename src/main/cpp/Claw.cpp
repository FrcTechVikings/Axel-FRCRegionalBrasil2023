#include "Claw.h"

void Claw::ClawLog(){}

void Claw::ClawSlide(bool lock, double percent){

    ClawSlowLeft.Set(ControlMode::PercentOutput, -1*percent*lock);
    ClawSlowRight.Set(ControlMode::PercentOutput, percent*lock);

}

void Claw::ClawInit(){

    ClawSlowRight.SetNeutralMode(NeutralMode::Brake);
    ClawSlowLeft.SetNeutralMode(NeutralMode::Brake);

    ClawSlowRight.SetSafetyEnabled(true);
    ClawSlowRight.SetExpiration(100_ms);

    ClawSlowLeft.SetSafetyEnabled(true);
    ClawSlowLeft.SetExpiration(100_ms);

}