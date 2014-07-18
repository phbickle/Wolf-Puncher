#include "Sprite.h"

void Sprite::Draw(SDL_Surface* surfaceToDrawOn)
{
	SDL_SetAlpha(pImage_, SDL_SRCALPHA, alpha_);
	SDL_Rect destR;
	destR.x = (Sint16)pos_.x - srcRect_.w / 2.0f; //making the sprite's x and y be at the center of the image
	destR.y = (Sint16)pos_.y - srcRect_.h / 2.0f;


	SDL_BlitSurface(pImage_, &srcRect_, surfaceToDrawOn, &destR);

}
