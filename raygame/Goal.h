#pragma once
#include "Agent.h"
class Goal : public Agent
{
public:
	Goal(float x, float y, const char* name, float maxForce, float maxSpeed) : Agent(x, y, name, maxForce, maxSpeed) {};
	void start() override;
};

