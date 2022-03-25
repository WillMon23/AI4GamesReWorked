#pragma once
#include "Component.h"
#include <time.h>
#include <math.h>
#include "Actor.h"
#include "Component.h"
#include "Transform2D.h"
#include "MoveComponent.h"
class WillsWanderComponent :
	public Component
{
	WillsWanderComponent(float circleDistance, float circleRadius, float wanderForce);
		void start() override;
		void update(float deltaTime) override;

		int getRadius() { return m_radius; };
		void setRadius(int value) { m_radius = value; };

		int getDistance() { return m_distance; };
		void setDistance(int value) { m_distance = value; };

	private:
		int m_distance;
		int m_radius;

		MathLibrary::Vector2 m_randomVector;
		MathLibrary::Vector2 m_velocity;

};

