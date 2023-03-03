#pragma once

namespace AutoConstants{}

namespace RobotConstants{

    const double wheelLenghtMeters = 0.4787; // Meters
    const double wheelRadiusMeters = 0.0762; // Meters

}

namespace DriveTrainConstants {

    const double maxSpeedPercentConstrain = 1.0;
    const double minSpeedPercentConstrain = 0.2;
    const double maxRotationPercentConstrain = 0.85;
    const double minRotationPercentConstrain = 0.05;
    const double standardPercentSpeed = 0.6;
    const double standardPercentRotation = 0.45;
    
}

namespace MotorsConstants {

    const int rearLeftCIN = 0;
    const int frontLeftCIN = 1;
    const int rearRightCIN = 2;
    const int frontRightCIN = 3;
    const int leftClawSnowBlower = 4;
    const int rightClawSnowBlower = 5;
    const int armRedLine = 6;

}

namespace SensorsConstants{

    const int topMicroSwitchDIO = 0;
    const int bottomMicroSwitchDIO = 1;
}

namespace JoystickConstants {

    const int buttonX = 1;
    const int buttonA = 2;
    const int buttonB = 3;
    const int buttonY = 4;
    const int buttonLB = 5;
    const int buttonRB = 6;
    const int buttonLT = 7;
    const int buttonRT = 8;
    const int buttonBACK = 9;
    const int buttonSTART = 10;

}

namespace ClawConstants{

    const double forwardSlidePercent = 0.6;
    const double returnSlidePercent = -0.6;

}

namespace ArmConstants{

    const double armPercentConstrain = 0.6;
    const double amrKeepUp = 0.05;
    const double armPercentUp = 0.6;
    const double armPercentDown = -0.5;
    const double operatorArmDeadBand = 0.5;

}