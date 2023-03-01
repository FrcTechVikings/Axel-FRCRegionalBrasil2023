#include "Claw.h"

void Claw::ClawLog(){}

void Claw::ClawFeed(bool lock, double percent){}

void Claw::ClawInit(){

    ClawSlonRight.SetNeutralMode(NeutralMode::Brake);
    ClawSlowLeft.SetNeutralMode(NeutralMode::Brake);
    ClawRedLine.SetNeutralMode(NeutralMode::Brake);

    ClawSlonRight.SetSafetyEnabled(true);
    ClawSlonRight.SetExpiration(100_ms);

    ClawSlowLeft.SetSafetyEnabled(true);
    ClawSlowLeft.SetExpiration(100_ms);

    ClawRedLine.SetSafetyEnabled(true);
    ClawRedLine.SetExpiration(100_ms);

}