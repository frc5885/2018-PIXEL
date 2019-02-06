// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CubeInOut.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

CubeInOut::CubeInOut(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::cubeIntake.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void CubeInOut::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CubeInOut::Execute()
{
	double leftTrigger = Robot::controllerState2->GetLeftTrig();
	double rightTrigger = Robot::controllerState2->GetRightTrig();

	// always <= 1.0!!!
	double intakeGain = 0.5;
	double outtakeGain = 1.0;
	double adjustmentSpeed = 0.5;

	// set the speed for the intake motors
	if (leftTrigger > .2)
	{
		// this is set for intake
		Robot::cubeIntake->rightMotor->Set(intakeGain * -leftTrigger);
		Robot::cubeIntake->leftMotor->Set(intakeGain * leftTrigger);
	}
	else if (rightTrigger > .2)
	{
		// this is set for outtake
		Robot::cubeIntake->rightMotor->Set(outtakeGain * rightTrigger);
		Robot::cubeIntake->leftMotor->Set(outtakeGain * -rightTrigger);
	}
	else if (Robot::controllerState2->GetRightBumper())
	{
		// this is set for adjusting the cube
		Robot::cubeIntake->rightMotor->Set(adjustmentSpeed);
		Robot::cubeIntake->leftMotor->Set(adjustmentSpeed);
	}
	else if (Robot::controllerState2->GetLeftBumper())
	{
		// this is set for adjusting the cube
		Robot::cubeIntake->rightMotor->Set(-adjustmentSpeed);
		Robot::cubeIntake->leftMotor->Set(-adjustmentSpeed);
	}
	else
	{
		Robot::cubeIntake->rightMotor->Set(0.0);
		Robot::cubeIntake->leftMotor->Set(0.0);
	}

	// angle the intake wrt the ground
	double leftY = Robot::controllerState2->GetLeftY();
	double anglerMotorSpeed = fabs(leftY) * .5;	// always <= 1.0!!!

	if (leftY < -0.2)
	{
		// lift the angler
		Robot::cubeIntake->angler->Set(-anglerMotorSpeed);
	}
	else if (leftY > 0.2)
	{
		// lower the angler
		Robot::cubeIntake->angler->Set(anglerMotorSpeed);
	}
	else
	{
		Robot::cubeIntake->angler->Set(0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CubeInOut::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void CubeInOut::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeInOut::Interrupted() {

}
