#pragma once

#include <frc/Joystick.h>
#include "Constants.h"

class CommandGroup {

    public:

        frc::Joystick pilotStick {0};
        frc::Joystick operatorStick {1};

        void InitAutoCommands();
        void OneCargoAuto(double delaySeconds, double dist, double tarmacExitDist);
        void ExitTarmacAuto(double delaySeconds);
        void InitCommands();
        void PeriodicCommands();
        void PilotCommands();
        void OperatorCommands();
        void Log();

    private:

        bool safeLock = 1;

};