#pragma once
#include "Agent.h"
class Goal : public Agent
{
public:
	/// <summary>
	/// Goal reprisents the end line of the maze for the player
	/// Giving the user a visual to find the ppath there headingds
	/// </summary>
	/// <param name="x"> Location at the x-axies</param>
	/// <param name="y"> Location at the y- axies</param>
	/// <param name="name"> Name associtated </param>
	/// <param name="maxForce">Max force if applied</param>
	/// <param name="maxSpeed">MAx speed if applied</param>
	Goal(float x, float y, const char* name, float maxForce, float maxSpeed) : Agent(x, y, name, maxForce, maxSpeed) {};
	void start() override;
};

