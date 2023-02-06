// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <string>
#include <frc/smartdashboard/SendableChooser.h>

//Pneumático
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
#include <frc/Joystick.h>

#include "CommandGroup.h"

class Robot : public frc::TimedRobot {

  public:

    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void TestInit() override;
    void TestPeriodic() override;

  private:

    frc::SendableChooser<std::string> m_chooser;
    std::string m_autoSelected;

    CommandGroup RobotCommands;

    // Pneumático

    frc::Compressor comp {0, frc::PneumaticsModuleType::CTREPCM};
    frc::DoubleSolenoid solenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1};
    frc::Joystick stickTeste {2};


};
