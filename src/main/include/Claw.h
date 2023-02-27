#pragma once

#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/smartdashboard/SendableChooser.h>

class Claw {

    public:

        WPI_VictorSPX ClawMotor = {MotorsConstants::clawSnowBlower};

        void ClawLog();
        void ClawFeed();
        void ClawInit();

    private:

};