// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  RobotCommands.InitCommands();

}

void Robot::AutonomousPeriodic() {

  m_autoSelected = m_chooser.GetSelected();

  RobotCommands.InitAutoCommands();

}

void Robot::TeleopInit() {

  // Inicializa o robô
  RobotCommands.InitCommands();

}

void Robot::TeleopPeriodic() {

  RobotCommands.PeriodicCommands();
  RobotCommands.PilotCommands();
  RobotCommands.OperatorCommands();
  RobotCommands.Log();

}

void Robot::DisabledInit() {

  RobotCommands.InitCommands();

}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {

  solenoid.Set(frc::DoubleSolenoid::Value::kOff);
  comp.Disable();

}

void Robot::TestPeriodic() {

  if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonA)){

      comp.EnableDigital();

  }else if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonB)){

      comp.Disable();

  }

  if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonX)){

      solenoid.Set(frc::DoubleSolenoid::Value::kForward);

  }else if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonY)){

      solenoid.Set(frc::DoubleSolenoid::Value::kReverse);

  }else if(stickTeste.GetRawButtonPressed(JoystickConstants::buttonBACK)){

      solenoid.Set(frc::DoubleSolenoid::Value::kOff);

  }

}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif