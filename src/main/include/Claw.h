#pragma once

#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>  

class Claw {

    public:

        WPI_VictorSPX ClawSlowLeft = {MotorsConstants::leftClawSnowBlower};
        WPI_VictorSPX ClawSlowRight = {MotorsConstants::rightClawSnowBlower};

        void ClawLog();
        void ClawSlide(bool lock, double percent);
        void ClawInit();

    private:

};