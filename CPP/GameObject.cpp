#include "GameObject.h"
#include <string>
#include <iostream>
#include <sstream>
#include "SDL_image.h"


GameObject::GameObject(ObjectType type, const Vec2& pos)
{
	LoadGameObject(type);
	pos_ = pos;
}


GameObject::~GameObject()
{
}


void GameObject::LoadGameObject(ObjectType type)
{
	std::ifstream objectData; //ifstream "In File Stream"
	std::string filename;

	switch (type)
	{
	case PLAYER:
		filename = "Player.dat";
		break;
	case ENEMY:
		filename = "Enemy.dat";
		break;
	case LARGEOBSTACLE:
		filename = "LargeObstacle.dat";
		break;
	case OBSTACLE:
		filename = "Obstacle.dat";
		break;
		
			

	default:
		break;
	}

	objectData.open(filename, std::ios::in);

	if (objectData.is_open())
	{
		processDataFile(objectData);
	}
	else
	{
		objectData.close();
		std::cerr << "Error Opening character data" << filename << std::endl;
	}

	objectData.close();
}

void GameObject::processDataFile(std::ifstream& file)
{
	std::string buf;

	while (file.good())
	{
		file >> buf;

		if (buf[0] == '#')
		{
			std::getline(file, buf);
		}
		else if (buf == "image:")
		{
			file >> buf;
			pImage_ = IMG_Load(buf.c_str());
		}
		else if (buf == "cellWidth:")
		{
			file >> buf;
			std::stringstream ss(buf);
			ss >> frameWidth_;
		}
		else if (buf == "cellHeight:")
		{
			file >> buf;
			std::stringstream ss(buf);
			ss >> frameHeight_;
		}
		else if (buf == "Animation")
		{
			file >> buf;
			anims_.insert(std::pair<std::string, AnimationData >(buf, AnimationData()));
		}
		else if (buf == "frameRate")
		{
			std::string animName;
			file >> animName;

			file >> buf;
			std::stringstream ss(buf);
			ss >> anims_[animName].frameRate;
		}
		else if (buf == "startframe")
		{
			std::string animName;
			file >> animName;

			file >> buf;
			std::stringstream ss(buf);
			ss >> anims_[animName].startFrame;
		}
		else if (buf == "numFrames")
		{
			std::string animName;
			file >> animName;

			file >> buf;
			std::stringstream ss(buf);
			ss >> anims_[animName].numFrames;
		}
		else if (buf == "defaultAnimation")
		{
			file >> buf;
			SetCurrAnim(buf);
		}
	}
	initAnim();
}