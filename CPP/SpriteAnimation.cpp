#include "SpriteAnimation.h"


SpriteAnimation::SpriteAnimation(void) : Sprite(),
frameWidth_(0),
frameHeight_(0),
numFrames_(0),
startFrame_(0),
currFrame_(0),
frameRate_(0.0f),
frameTime_(0.0f),
framesWide_(0),
framesHigh_(0),
isLooped_(false),
isPlaying_(false)
{

}

SpriteAnimation::SpriteAnimation(SDL_Surface* image, Vec2 pos, SDL_Rect srcRect,
	Uint8 alpha, Uint16 frameWidth, Uint16 frameHeight,
	Uint16 startFrame, Uint16 numFrames, float frameRate)
	:
	Sprite(image, pos, srcRect, alpha),
	frameWidth_(frameWidth),
	frameHeight_(frameHeight),
	numFrames_(numFrames),
	startFrame_(startFrame),
	currFrame_(0),
	frameRate_(frameRate),
	frameTime_(0.0f),
	framesWide_(0),
	framesHigh_(0),
	isLooped_(false),
	isPlaying_(false)
{
	framesWide_ = pImage_->w / frameWidth_;
	framesHigh_ = pImage_->h / frameHeight_;
	updateSrcFrame();
}



SpriteAnimation::~SpriteAnimation()
{

}

void SpriteAnimation::Update(float deltaTime)
{
	if (isPlaying_)
	{
		frameTime_ += deltaTime;
		if (frameTime_ > frameRate_)
		{
			frameTime_ -= frameRate_;
			currFrame_++;

			if (currFrame_ >= numFrames_)
			{
				currFrame_ = 0;
				if (!isLooped_)
				{
					isPlaying_ = false;
				}
			}
			updateSrcFrame(); //update it only after we change it
		}
	}
}

void SpriteAnimation::updateSrcFrame()
{
	Uint16 absIndex = startFrame_ + currFrame_;

	Uint16 col = absIndex % framesWide_;
	srcRect_.x = col * frameWidth_;

	Uint16 row = absIndex % framesHigh_;
	srcRect_.y = row * frameHeight_;

	srcRect_.w = frameWidth_; //could put these in the constructor or their own function, but this is easy to read because it's all together
	srcRect_.h = frameHeight_;

}