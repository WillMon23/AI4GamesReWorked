#include "StateMachineComponent.h"
#include "Actor.h"
#include "PathfindComponent.h"
#include "WanderComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"

void StateMachineComponent::start()
{
	Component::start();

	//Gets the owners Wander Compoent 
	m_wanderComponent = getOwner()->getComponent<WanderComponent>();
	//Gets The Force being Used from the users Wander Component
	m_wanderForce = m_wanderComponent->getSteeringForce();
	//Gets the owners pathComponent
	m_pathfindComponent = getOwner()->getComponent<PathfindComponent>();
	//Sets Current State to Idle
	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	Component::update(deltaTime);
	//Sets a timer taking delta time for updates 
	m_timesUp += deltaTime;

	//Checks for the current state of the game 
	switch (m_currentState)
	{
		//Case Idle
	case IDLE:
		//All states are still
		m_wanderComponent->setSteeringForce(0);
		m_pathfindComponent->onDisableMovement();

		//Once timer his 4 seconds 
		if (m_timesUp > 5)
		{
			//Changes the current state to seek
			m_currentState = SEEK;
			//rests the timer to 0
			m_timesUp = 0;
		}
		break;
		//Case Wander
	case WANDER:
		//Meant to disable pathfinding 
		m_pathfindComponent->onDisableMovement();
		//Activates the force for wandering 
		m_wanderComponent->setSteeringForce(m_wanderForce);
		//Once The Time is up reaches 5
		if (m_timesUp > 6)
		{
			//current state will change to seek
			m_currentState = SEEK;
			//rests the timer to 0
			m_timesUp = 0;
		}
		break;
		//Case Seek
	case SEEK:
		//pathfind component is enabbled 
		m_pathfindComponent->onEnableMovememt();
		//Sets tje steering force to 0
		m_wanderComponent->setSteeringForce(0);
		//Once The Time is up reaches 10
		if (m_timesUp > 5)
		{
			//current state will change to Wander
			m_currentState = WANDER;
			//rests the timer to 0
			m_timesUp = 0;
		}

		break;
	}
}
