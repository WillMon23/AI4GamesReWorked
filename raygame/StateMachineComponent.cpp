#include "StateMachineComponent.h"
#include "Actor.h"
#include "SeekComponent.h"
#include "PathfindComponent.h"
#include "WanderComponent.h"
#include "Transform2D.h"

void StateMachineComponent::start()
{
	Component::start();

	m_seekComponent = getOwner()->getComponent<SeekComponent>();
	m_seekComponent->setTarget(getOwner());
	m_seekForce = m_seekComponent->getSteeringForce();

	m_wanderComponent = getOwner()->getComponent<WanderComponent>();
	m_wanderForce = m_wanderComponent->getSteeringForce();

	m_pathfindComponent = getOwner()->getComponent<PathfindComponent>();

	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	Component::update(deltaTime);

	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;

	switch (m_currentState)
	{
	case IDLE:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(1000.0f);
		m_pathfindComponent->onDisable();

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case WANDER:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(1000);
		m_pathfindComponent->onEnabled();

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_wanderComponent->setSteeringForce(0);

		if (!targetInRange)
			setCurrentState(WANDER);

		break;
	}
}
