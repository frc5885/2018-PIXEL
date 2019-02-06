// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "Definitions.h"
#include "AutoSwitchScaleStraight.h"
#include "Commands/RobotStraight.h"
#include "Commands/RobotTurn.h"
#include "Commands/RobotDwell.h"
#include "Commands/RobotCubeEjector.h"
#include "Commands/RobotScissorLift.h"

// from definitions.h - do NOT un-comment!!!
// #define SIDE_DISTANCE 29.7	// distance from side wall for start of auto

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoSwitchScaleStraight::AutoSwitchScaleStraight(double dwellTime, int switchOrScale, int leftOrRight)
{
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

	// To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

              // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

	int turnDirection = 0;

	// initial dwell - wait for other robots
    AddSequential(new RobotDwell(dwellTime));

	// go down the field
	AddSequential(new RobotDwell(dwellTime));
	AddSequential(new RobotStraight(
		Robot::longDistance[switchOrScale] - Robot::autoLength / 2.0,
		Robot::autoStraightMotorSpeed));
	AddSequential(new RobotDwell(Robot::autoDwellTime));

	// turn towards the switch or scale
	turnDirection = (leftOrRight == AUTO_START_LEFT) ? TURN_RIGHT : TURN_LEFT;
	AddSequential(new RobotTurn(turnDirection, Robot::autoTurnMotorSpeed));
	AddSequential(new RobotDwell(Robot::autoDwellTime));

	// approach the switch or scale
	AddSequential(new RobotStraight(
			Robot::shortDistance[switchOrScale] - ((Robot::autoLength + Robot::autoWidth) / 2.0) -
			SIDE_DISTANCE,
			Robot::autoStraightMotorSpeed));
	AddSequential(new RobotDwell(Robot::autoDwellTime));

	// raise the scissor lift if we are depositing on the scale
	if (switchOrScale == AUTO_SCALE)
	{
		AddSequential(new RobotScissorLift(Robot::autoScissorMotorSpeed));
	}

	// eject the cube
	AddSequential(new RobotCubeEjector());
	AddSequential(new RobotDwell(Robot::autoDwellTime));

	// lower the scissor lift if we are depositing on the scale
	if (switchOrScale == AUTO_SCALE)
	{
		AddSequential(new RobotScissorLift(-Robot::autoScissorMotorSpeed));
	}
}