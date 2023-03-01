#pragma once

#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>  

class Claw {

    public:

        WPI_VictorSPX ClawSlowLeft = {MotorsConstants::leftClawSnowBlower};
        WPI_VictorSPX ClawSlonRight = {MotorsConstants::rightClawSnowBlower};
        WPI_VictorSPX ClawRedLine = {MotorsConstants::clawRedLine};

        void ClawLog();
        void ClawFeed(bool lock, double percent);
        void ClawInit();

    private:

};