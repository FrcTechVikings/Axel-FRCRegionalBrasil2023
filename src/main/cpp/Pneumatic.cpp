#include "Pneumatic.h"
#include <frc/smartdashboard/SmartDashboard.h>

void Pneumatics::PneumaticLog(){}

void Pneumatics::Init(){

    solenoid.Set(frc::DoubleSolenoid::Value::kOff);
    //solenoid.Set(frc::DoubleSolenoid::Value::kForward);
    comp.Disable();
   
}

void Pneumatics::PneumaticFeed(){
    if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonA)){

      comp.EnableDigital();

  }else if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonB)){

      comp.Disable();

  }

  if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonX)){

      solenoid.Set(frc::DoubleSolenoid::Value::kForward);
      //solenoid.Toggle();

  }else if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonY)){

      solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
      //solenoid.Toggle();

  }else if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonBACK)){

      solenoid.Set(frc::DoubleSolenoid::Value::kOff);

  }
}

