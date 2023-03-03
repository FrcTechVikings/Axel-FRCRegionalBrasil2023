#pragma once

#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>  
#include <frc/DigitalInput.h>

class Arm {

    public:

        WPI_VictorSPX ArmRedLine = {MotorsConstants::armRedLine};

        frc::DigitalInput topLimitSwitch {SensorsConstants::topMicroSwitchDIO};
        frc::DigitalInput bottomLimitSwitch {SensorsConstants::bottomMicroSwitchDIO};

        int armControlDirection = 0;
        
        void ArmLog();
        void ArmFeed(bool lock, double percent);
        void ArmSwitchUp();
        void ArmSwitchDown();
        void ArmPeriodic(bool lock, double JoyAxisY); //ele vai analisar quem vai controlar 
        void ArmInit();
    
    private:

        double operatorStickValue = 0.0;

};