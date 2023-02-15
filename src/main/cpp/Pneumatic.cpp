#include "Pneumatic.h"
#include <frc/smartdashboard/SmartDashboard.h>

void Pneumatics::PneumaticLog(){}

void Pneumatics::Init(){

    solenoid.Set(frc::DoubleSolenoid::Value::kForward);
    comp.Disable();
   
}

void Pneumatics::EnableCompressor(){

    comp.EnableDigital();
     
}

void Pneumatics::DisableCompressor(){

    comp.Disable();
     
}

void Pneumatics::AtivaSolenoide(){
   solenoid.Toggle(); //Troca o estado

}

