// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoCrossLine.h"
#include "Commands/AutoSwitchScaleCross.h"
#include "Commands/AutoSwitchScaleStraight.h"
#include "Commands/CubeEjector.h"
#include "Commands/CubeInOut.h"
#include "Commands/RobotCubeEjector.h"
#include "Commands/RobotDwell.h"
#include "Commands/RobotScissorLift.h"
#include "Commands/RobotStraight.h"
#include "Commands/RobotTurn.h"
#include "Commands/TankDrive.h"
#include "Commands/TeleLift.h"
#include "Commands/Teleoperation.h"
#include "Commands/UnlockArm.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    xboxController.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getXboxController() {
   return xboxController;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS