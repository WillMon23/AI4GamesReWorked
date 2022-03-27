#include "Goal.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "AABBCollider.h"
#include "MazeScene.h"

void Goal::start()
{
	Agent::start();
	//sets its collider  based off the collliders pre desisions 
	setCollider(new AABBCollider(Maze::TILE_SIZE, Maze::TILE_SIZE, this));
	//Sets a sprite componenet to be attached to the agent
	addComponent(new SpriteComponent("Images/bullet.png"));
	//Sets the scale to set the png image 
	getTransform()->setScale({60, 60});

}
