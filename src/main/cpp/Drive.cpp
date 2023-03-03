#include "Drive.h"

void Drivetrain::DriveLog(){}

void Drivetrain::Drive(double yAxis, double zAxis, bool lock){

    yAxisJoy = (0.5*pow(yAxis,3) + (0.5*yAxis));
    zAxisJoy = zAxis;

    ySpeed = yAxisJoy*direction*lock*percentSpeed*(-1); 
    zRotation = zAxisJoy*lock*percentRotation;
    drivetrain.CurvatureDrive(ySpeed,zRotation,true);
    
}

void Drivetrain::DriveSpeedChange(int proportion, double gain){

    percentRotation += gain * proportion;
    percentSpeed += gain * proportion;
    
    if(percentSpeed > DriveTrainConstants::maxSpeedPercentConstrain){

        percentRotation = DriveTrainConstants::maxRotationPercentConstrain;
        percentSpeed = DriveTrainConstants::maxSpeedPercentConstrain;

    }else if(percentSpeed < DriveTrainConstants::minSpeedPercentConstrain){

        percentRotation = DriveTrainConstants::minRotationPercentConstrain;
        percentSpeed = DriveTrainConstants::minSpeedPercentConstrain;

    }
}

void Drivetrain::DriveSpeedMax(){

    percentRotation = DriveTrainConstants::maxRotationPercentConstrain;
    percentSpeed = DriveTrainConstants::maxSpeedPercentConstrain;

}

void Drivetrain::DriveSpeedStandard(){

    percentRotation = DriveTrainConstants::standardPercentRotation;
    percentSpeed = DriveTrainConstants::standardPercentSpeed;

}

void Drivetrain::DriveDirection(){

    direction *= -1;
    
}

void Drivetrain::DriveInit(){
    
    rearLeft.SetNeutralMode(NeutralMode::Brake);
    rearRight.SetNeutralMode(NeutralMode::Brake);
    frontLeft.SetNeutralMode(NeutralMode::Coast);
    frontRight.SetNeutralMode(NeutralMode::Coast);

    drivetrain.SetSafetyEnabled(true);
    drivetrain.SetExpiration(100_ms);

    motorsRight.SetInverted(true); //inverte 
    drivetrain.CurvatureDrive(0.0, 0.0, true); //movimentação em curvas

    ySpeed = 0.0;
    zRotation = 0.0;
    yAxisJoy = 0.0;
    zAxisJoy = 0.0;
    direction = 1;  
    percentSpeed = DriveTrainConstants::standardPercentSpeed;
    percentRotation = DriveTrainConstants::standardPercentRotation;  

}