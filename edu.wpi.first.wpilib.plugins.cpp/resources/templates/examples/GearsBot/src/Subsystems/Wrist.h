#ifndef Wrist_H
#define Wrist_H

#include <Commands/PIDSubsystem.h>
#include <Potentiometer.h>
#include <Victor.h>

/**
 * The wrist subsystem is like the elevator, but with a rotational joint instead
 * of a linear joint.
 */
class Wrist : public PIDSubsystem {
public:
	Wrist();

	void InitDefaultCommand();

	/**
	 * The log method puts interesting information to the SmartDashboard.
	 */
	void Log();

/**
 * Use the potentiometer as the PID sensor. This method is automatically
 * called by the subsystem.
 */
double ReturnPIDInput();

/**
 * Use the motor as the PID output. This method is automatically called by
 * the subsystem.
 */
void UsePIDOutput(double d);

private:
	std::unique_ptr<SpeedController> motor = std::make_unique<Victor>(6);
	std::unique_ptr<Potentiometer> pot;

	constexpr double kP_real = 1, kP_simulation = 0.05;
};

#endif  // Wrist_H
