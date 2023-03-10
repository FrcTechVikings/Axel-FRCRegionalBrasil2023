#pragma once

#include <frc/Joystick.h>
#include "Constants.h"

//Sistemas do robô
#include "Drive.h"
#include "Arm.h"
#include "Claw.h"

class CommandGroup {

    public:

        frc::Joystick pilotStick {0};
        frc::Joystick operatorStick {1};

        Drivetrain RobotDrive;
        Arm RobotArm;
        Claw RobotClaw;
        
        void InitAutoCommands();
        void AutoPrincipal(double delay_s, double distPontuacao_m, double distSaida_m);
        void AutoNothing();
        void InitCommands();
        void PeriodicCommands();
        void PilotCommands();
        void OperatorCommands();
        void Log();

        void Teste();

    private:

        bool safeLock = 1;
        bool estadoCompressor = 1;
        frc::Timer autoTimer;
        bool executeOnce = 0;

};