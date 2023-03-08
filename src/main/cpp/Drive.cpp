#include "Drive.h"

void Drivetrain::DriveLog(){

    frc::SmartDashboard::PutNumber("MotorRight", motorsRight.Get());
    frc::SmartDashboard::PutNumber("MotorLeft", motorsLeft.Get());
    frc::SmartDashboard::PutNumber("ySpeed", ySpeed);
    frc::SmartDashboard::PutNumber("zRotation", zRotation);
    frc::SmartDashboard::PutNumber("yAxisJoy", yAxisJoy);
    frc::SmartDashboard::PutNumber("zAxisJoy", zAxisJoy);
    frc::SmartDashboard::PutNumber("direction", direction);
    frc::SmartDashboard::PutNumber("Nível de Velocidade", round(percentSpeed * 10));
    frc::SmartDashboard::PutNumber("percentRotation", percentRotation);
    frc::SmartDashboard::PutNumber("percentRotationTemp", percentRotationTemp);
    frc::SmartDashboard::PutNumber("estadoSlowTurn", estadoSlowTurn);
    
}

void Drivetrain::Drive(double yAxis, double zAxis, bool lock){

    yAxisJoy = (0.5*pow(yAxis,3) + (0.5*yAxis));
    zAxisJoy = zAxis;

    ySpeed = yAxisJoy*direction*lock*percentSpeed; 
    zRotation = zAxisJoy*lock*percentRotation*-1;
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
    percentRotationTemp = percentRotation;
    estadoSlowTurn = 0;

}

void Drivetrain::DriveSlowTurn(){

    if(estadoSlowTurn == 0){

        percentRotationTemp = percentRotation;
        percentRotation = DriveTrainConstants::slowTurnPercentRotation;
        estadoSlowTurn = 1;

    } else {

        percentRotation = percentRotationTemp;
        estadoSlowTurn = 0;
        
    }


}