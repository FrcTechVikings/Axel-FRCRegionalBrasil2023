// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {

  m_chooser.SetDefaultOption(AutoConstants::AutoPrincipal, AutoConstants::AutoPrincipal);
  m_chooser.AddOption(AutoConstants::SemAuto, AutoConstants::SemAuto);

  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  RobotCommands.InitCommands();

  // Camera

  camera.SetResolution(640,480);
  camera.SetFPS(30);
  camera = frc::CameraServer::StartAutomaticCapture(0);

  server = frc::CameraServer::GetServer();

  server.SetSource(camera);

  //cvsink = frc::CameraServer::GetVideo();

  //cvsink = new cs::CvSink("cam1cv");
  //cvsink->SetSource(camera);
  //cvsink->SetEnabled(true);

}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {

  RobotCommands.InitAutoCommands();

  m_autoSelected = m_chooser.GetSelected();

}

void Robot::AutonomousPeriodic() {

  if(m_autoSelected == AutoConstants::AutoPrincipal){

    RobotCommands.AutoPrincipal(frc::SmartDashboard::GetNumber("Delay (segundos)", 0.2), frc::SmartDashboard::GetNumber("Distância Para Pontuação (metros)", 2.0), frc::SmartDashboard::GetNumber("Distância de Retorno (metros)", 5.0));

  }else{

    RobotCommands.AutoNothing();

  }

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

  RobotCommands.InitCommands();

}

void Robot::TestPeriodic() {

  RobotCommands.Teste();

}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif