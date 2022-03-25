#include "WillsWanderComponent.h"

void WillsWanderComponent::start()
{
	srand(time(NULL));
	setDistance(5);
	setRadius(10);
}

void WillsWanderComponent::update(float deltaTime)
{
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();

	//Owers Velocity normalized 
	m_velocity = getOwner()->getComponent<MoveComponent>()->getVelocity().getNormalized();

	float randX = rand() % 10;
	float randY = rand() % 10;

	m_randomVector = { cos(randX), sin(randY) };

	//The posistion of the circle 
	MathLibrary::Vector2 circleOffset = ownerPosition + m_velocity * getDistance();

	MathLibrary::Vector2 circlePosition = circleOffset + ownerPosition;
}
