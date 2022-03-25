#pragma once
#include "Component.h"
#include <Vector2.h>

enum State
{
	IDLE,
	WANDER,
	SEEK
};

class SeekComponent;
class WanderComponent;
class PathfindComponent;

class StateMachineComponent :
	public Component
{
public:
	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	WanderComponent* m_wanderComponent;
	PathfindComponent* m_pathfindComponent;
	float m_timesUp;
	float m_seekForce;
	float m_wanderForce;
	MathLibrary::Vector2 m_pathFindForce;
};

