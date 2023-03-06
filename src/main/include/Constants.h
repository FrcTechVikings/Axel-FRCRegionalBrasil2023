#pragma once

namespace AutoConstants{}

namespace RobotConstants{

    const double wheelLenghtMeters = 0.4787; // Meters
    const double wheelRadiusMeters = 0.0762; // Meters

}

namespace DriveTrainConstants {

    const double maxSpeedPercentConstrain = 1.0; // Porcentagem
    const double minSpeedPercentConstrain = 0.2; // Porcentagem
    const double maxRotationPercentConstrain = 0.85; // Porcentagem
    const double minRotationPercentConstrain = 0.05; // Porcentagem
    const double standardPercentSpeed = 0.6; // Porcentagem
    const double standardPercentRotation = 0.45; // Porcentagem
    
}

namespace MotorsConstants {

    const int rearLeftCIN = 0; // ID
    const int frontLeftCIN = 1; // ID
    const int rearRightCIN = 2; // ID
    const int frontRightCIN = 3; // ID
    const int armRedLine = 4; // ID
    const int leftClawSnowBlower = 5; // ID
    const int rightClawSnowBlower = 6; // ID

}

namespace SensorsConstants{

    const int topMicroSwitchDIO = 0; // ID
    const int bottomMicroSwitchDIO = 1; // ID
    const int frontMicroSwitchDIO = 2; // ID
    const int rearMicroSwitchDIO = 3; // ID
}

namespace JoystickConstants {

    const int buttonX = 1; // ID
    const int buttonA = 2; // ID
    const int buttonB = 3; // ID
    const int buttonY = 4; // ID
    const int buttonLB = 5; // ID
    const int buttonRB = 6; // ID
    const int buttonLT = 7; // ID
    const int buttonRT = 8; // ID
    const int buttonBACK = 9; // ID
    const int buttonSTART = 10; // ID

}

namespace ClawConstants{

    const double forwardSlidePercent = -1; // Porcentagem
    const double returnSlidePercent = 1; // Porcentagem

}

namespace ArmConstants{

    const double armPercentConstrain = 0.6; // Porcentagem
    const double amrKeepUp = 0.05; // Porcentagem
    const double armPercentUp = 0.6; // Porcentagem
    const double armPercentDown = -0.5; // Porcentagem
    const double operatorArmDeadBand = 0.5; // Porcentagem

}