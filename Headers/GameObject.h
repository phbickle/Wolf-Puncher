#pragma once

#include <fstream>
#include "MathUtils.h"
#include "SpriteAnimation.h"

class GameObject :
	public SpriteAnimation
{
	int _x;
	int _y;
	float _Vx;
	float _Vy;

	int _initialX;
	int	_initialY;
	int	_initialVx;
	int	_initialVy;

	enum ObjectType
	{
		PLAYER,
		ENEMY,
		LARGEOBSTACLE,
		OBSTACLE
	};
protected:
	Vec2 velocity_;

	void processDataFile(std::ifstream& file);

public:
	GameObject(ObjectType type, const Vec2& pos);
	GameObject(const Vec2& pos) 
	{
		pos_ = pos;
	}
	virtual void LoadGameObject(ObjectType type);
	virtual	~GameObject(void);
};



