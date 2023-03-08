#pragma once

#include "ctre/Phoenix.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Encoder.h>
#include "Constants.h"

class Drivetrain {

    public:
        
        WPI_VictorSPX rearLeft = {MotorsConstants::rearLeftCIN};
        WPI_VictorSPX rearRight = {MotorsConstants::rearRightCIN};
        WPI_VictorSPX frontLeft = {MotorsConstants::frontLeftCIN};
        WPI_VictorSPX frontRight = {MotorsConstants::frontRightCIN};

        frc::MotorControllerGroup motorsRight{rearRight, frontRight};
        frc::MotorControllerGroup motorsLeft{rearLeft, frontLeft};
        
        frc::DifferentialDrive drivetrain{motorsLeft, motorsRight};

        frc::Encoder leftDriveEncoder {SensorsConstants::leftDriveEncoderAChannel, SensorsConstants::leftDriveEncoderBChannel};
        frc::Encoder rightDriveEconder {SensorsConstants::rightDriveEncoderAChannel, SensorsConstants::rightDriveEncoderBChannel, true};

        void DriveLog();
        void Drive(double yAxis, double zAxis, bool lock);
        void DriveSpeedChange(int proportion, double gain);
        void DriveSpeedMax();
        void DriveSpeedStandard();
        void DriveDirection();
        void DriveInit();
        void DriveSlowTurn();
        void ResetEnconder();
        double GetDistanceEncoder();

    private:

        double ySpeed = 0.0;
        double zRotation = 0.0;
        double yAxisJoy = 0.0;
        double zAxisJoy = 0.0;
        int direction = 1;
        double percentSpeed = DriveTrainConstants::standardPercentSpeed;
        double percentRotation = DriveTrainConstants::standardPercentRotation;
        double percentRotationTemp = percentRotation;
        bool estadoSlowTurn = 0;
        
};