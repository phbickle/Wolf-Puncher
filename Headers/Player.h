#pragma once
#include "SpriteAnimation.h"
class Player :
	public SpriteAnimation
{
public:
	Player();
	~Player();

	int playerLegStrength;
	int anger;
	int sadness;
	float boredom;


	enum PlayerStates
	{
		RUNNING, //default state
		JUMPING, //rising in the air
		FALLING, //falling from the air
		PUNCHING, //attacking

	};

	void Jump();
	void Pawnch();
	void Fall();
	void getHit();
	void runInto();
	void coveredInBlank();
};
