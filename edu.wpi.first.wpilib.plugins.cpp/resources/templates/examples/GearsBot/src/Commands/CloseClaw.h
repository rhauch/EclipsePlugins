#ifndef CloseClaw_H
#define CloseClaw_H

#include <Commands/Command.h>

/**
 * Opens the claw for one second. Real robots should use sensors, stalling
 * motors is BAD!
 */
class CloseClaw : public Command {
public:
	CloseClaw();
	void Initialize();
	bool IsFinished();
	void End();
};

#endif  // CloseClaw_H
