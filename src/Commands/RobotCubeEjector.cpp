// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotCubeEjector.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RobotCubeEjector::RobotCubeEjector(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::aircontrolModule.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RobotCubeEjector::Initialize()
{
	m_timer.Reset();
	m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void RobotCubeEjector::Execute()
{
	if (m_timer.Get() < 1.0)
	{
		RobotMap::aircontrolModuleCubeKicker->Set(DoubleSolenoid::kForward);
	}
	else
	{
		RobotMap::aircontrolModuleCubeKicker->Set(DoubleSolenoid::kReverse);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RobotCubeEjector::IsFinished()
{
    return ((m_timer.Get() > 1.5) ? true : false);
}

// Called once after isFinished returns true
void RobotCubeEjector::End()
{
	RobotMap::aircontrolModuleCubeKicker->Set(DoubleSolenoid::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotCubeEjector::Interrupted() {

}
