#include "LowGoal.h"

#include "Commands/SetPivotSetpoint.h"
#include "Commands/SetCollectionSpeed.h"
#include "Commands/ExtendShooter.h"
#include "Robot.h"

LowGoal::LowGoal() {
	AddSequential(new SetPivotSetpoint(Pivot::LOW_GOAL));
	AddSequential(new SetCollectionSpeed(Collector::REVERSE));
	AddSequential(new ExtendShooter());
}
