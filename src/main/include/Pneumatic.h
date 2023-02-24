#pragma once

#include "Constants.h"
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>

class Pneumatics {

    public:

        void PneumaticLog();
        void Init();
        void EnableCompressor();
        void DisableCompressor();
        void AtivaSolenoide();
          
    
    private:

        frc::Compressor comp {0, frc::PneumaticsModuleType::CTREPCM};
        frc::DoubleSolenoid solenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1};
        //frc::DoubleSolenoid exampleDoublePH{9, frc::PneumaticsModuleType:: REVPH, 4, 5};

};