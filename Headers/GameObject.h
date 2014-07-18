#pragma once

#include <fstream>
#include "MathUtils.h"
#include "SpriteAnimation.h"

class GameObject :
	public SpriteAnimation
{
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



