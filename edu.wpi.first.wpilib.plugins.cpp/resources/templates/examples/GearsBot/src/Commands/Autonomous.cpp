#include "Autonomous.h"

#include <iostream>

#include "CloseClaw.h"
#include "DriveStraight.h"
#include "PrepareToPickup.h"
#include "Pickup.h"
#include "Place.h"
#include "SetDistanceToBox.h"
#include "SetWristSetpoint.h"

Autonomous::Autonomous() : CommandGroup("Autonomous") {
	AddSequential(new PrepareToPickup());
	AddSequential(new Pickup());
	AddSequential(new SetDistanceToBox(0.10));
	// AddSequential(new DriveStraight(4));  // Use Encoders if ultrasonic is broken
	AddSequential(new Place());
	AddSequential(new SetDistanceToBox(0.60));
	// AddSequential(new DriveStraight(-2));  // Use Encoders if ultrasonic is broken
	AddParallel(new SetWristSetpoint(-45));
	AddSequential(new CloseClaw());
}
