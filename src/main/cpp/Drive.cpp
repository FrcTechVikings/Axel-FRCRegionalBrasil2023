#include "Drive.h"

void Drivetrain::DriveLog(){}

void Drivetrain::Drive(double yAxis, double zAxis, bool lock){}

void Drivetrain::DriveSpeed(int proportion, double gain){}

void Drivetrain::DriveSpeedMax(){}

void Drivetrain::DriveSpeedStandard(){}

void Drivetrain::DriveDirection(){}

void Drivetrain::DriveInit(){
    
    rearLeft.SetNeutralMode(NeutralMode::Brake);
    rearRight.SetNeutralMode(NeutralMode::Brake);
    frontLeft.SetNeutralMode(NeutralMode::Coast);
    frontRight.SetNeutralMode(NeutralMode::Coast);

    drivetrain.SetSafetyEnabled(true);
    drivetrain.SetExpiration(100_ms);

}