#pragma once
#include "Sprite.h"

#include <map>


class SpriteAnimation :
	public Sprite
{
public:
	struct AnimationData //types at the top
	{
		Uint16 startFrame;
		float frameRate;
		Uint16 numFrames;
	};
protected: //class members
	std::map<std::string, AnimationData> anims_;

	Uint16 numFrames_; //(up to 256 frames with Uint8,,, low memory devices might want to use this)
	Uint16 currFrame_;
	Uint16 startFrame_;

	Uint16 framesWide_;
	Uint16 framesHigh_;
	Uint16 frameWidth_;
	Uint16 frameHeight_;

	float frameRate_;
	float frameTime_;

	bool isLooped_;
	bool isPlaying_;

	void updateSrcFrame(); //recalculate the srcRect_ based on the current frame
	void initAnim();


public: //functions
	SpriteAnimation(void);
	SpriteAnimation(SDL_Surface* image, Vec2 pos, SDL_Rect srcRect,
		Uint8 alpha, Uint16 frameWidth, Uint16 frameHeight,
		Uint16 startFrame, Uint16 numframes, float frameRate);
	// Constructor ^^ must take all of its own data that will be used as well as Sprite's ^^
	virtual ~SpriteAnimation(void);

	void Update(float deltaTime); //keeps track of the time and switches frames

	void Play(bool looped)
	{
		isLooped_ = looped;
		isPlaying_ = true;
	}

	void Pause()
	{
		isPlaying_ = false;
	}

	void Stop()
	{
		isPlaying_ = false;
		currFrame_ = 0;
	}

	//frameIndex is the relative frame index
	void SetCurrFrame(Uint16 frameIndex)
	{
		//the absolute frame is == startFrame + currFame
		if (frameIndex < 0)
		{
			currFrame_ = 0;
		}
		else if (frameIndex >= numFrames_)
		{
			currFrame_ = numFrames_ - 1;
		}
		else
		{
			currFrame_ = 0;
		}

	}

	void SetStartFrame(Uint16 startFrame)
	{
		startFrame_ = startFrame;
	}

	void SetNumFrames(Uint16 numFrames)
	{
		numFrames_ = numFrames;
	}
	void SetCurrAnim(std::string animation, Uint16 currFrame = 0)
	{
		AnimationData newAnim = anims_[animation];
		frameRate_ = newAnim.frameRate;
		startFrame_ = newAnim.startFrame;
		currFrame_ = currFrame;
		numFrames_ = newAnim.numFrames;
	}

	Uint16 GetWidth()
	{
		return frameWidth_;
	}

	Uint16 GetHeight()
	{
		return frameHeight_;
	}

	Uint16 GetCurrFrame()
	{
		return currFrame_;
	}

	bool GetIsPlaying()
	{
		return isPlaying_;
	}

	bool GetIsLooped()
	{
		return isLooped_;
	}
};

