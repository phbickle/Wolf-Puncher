#pragma once
#include "Game.h"
#include "Sprite.h"
#include "SpriteAnimation.h"

class ExampleGame : public Game
{
private:
	virtual void loadAssets();
	virtual void update(float deltaTime);
	virtual void draw();

	//for testing///////////////////////////////////////////
	//Sprite* pTestSprite_;
	SpriteAnimation* pTestSprite_;

public:

	ExampleGame(void) : Game(), pTestSprite_(NULL)
	{}

	virtual ~ExampleGame(void)
	{
		if (pTestSprite_)
		{
			delete pTestSprite_;
		}
	}
};

