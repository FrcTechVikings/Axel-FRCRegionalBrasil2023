#pragma once

#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/DigitalInput.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
#include <frc/smartdashboard/SmartDashboard.h> 

class Claw {

    public:

        WPI_VictorSPX ClawSlowLeft = {MotorsConstants::leftClawSnowBlower};
        WPI_VictorSPX ClawSlowRight = {MotorsConstants::rightClawSnowBlower};

        frc::DigitalInput frontLimitSwitch {SensorsConstants::frontMicroSwitchDIO};
        frc::DigitalInput rearLimitSwitch {SensorsConstants::rearMicroSwitchDIO};
        
        void ClawLog();
        void ClawSlideForward(bool lock, double percent);
        void ClawSlideReturn(bool lock, double percent);
        void ClawStop();
        void ClawInit();
        void EnableCompressor();
        void DisableCompressor();
        void AtivaSolenoide();

    private:

        frc::Compressor comp {0, frc::PneumaticsModuleType::CTREPCM};
        frc::DoubleSolenoid solenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1};

};