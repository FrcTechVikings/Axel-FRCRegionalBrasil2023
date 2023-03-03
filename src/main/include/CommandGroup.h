#pragma once

#include <frc/Joystick.h>
#include "Constants.h"

//Sistemas do robô
#include "Pneumatic.h"
#include "Drive.h"
#include "Arm.h"
#include "Claw.h"

class CommandGroup {

    public:

        frc::Joystick pilotStick {0};
        frc::Joystick operatorStick {1};

        Pneumatics RobotPneumatic;
        Drivetrain RobotDrive;
        Arm RobotArm;
        Claw RobotClaw;
        
        void InitAutoCommands();
        void InitCommands();
        void PeriodicCommands();
        void PilotCommands();
        void OperatorCommands();
        void Log();

    private:

        bool safeLock = 1;
        bool estadoCompressor = 0;

};