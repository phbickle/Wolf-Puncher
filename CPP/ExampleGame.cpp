#include "ExampleGame.h"

void ExampleGame::loadAssets()
{
	//test code
	SDL_Surface* temp = IMG_Load("Yu-gi-black-pants-856x107(reverse).png");
	SDL_Surface* temp2 = SDL_DisplayFormatAlpha(temp);

	SDL_FreeSurface(temp);

	SDL_Rect srcRect = SDL_Rect();
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 107;
	srcRect.h = 107;



	pTestSprite_ = new SpriteAnimation(temp2, Vec2(100.0f, 100.0f), srcRect, 255, 107, 107, 0, 8, 0.01f);
	pTestSprite_->Play(true);
}

void ExampleGame::update(float deltaTime)
{
	pTestSprite_->Update(deltaTime);
}

void ExampleGame::draw()
{
	pTestSprite_->Draw(pDisplay_);
	Game::draw();
}

/*
void ExampleGame::draw();
{
	pTestSprite_->Draw(pDisplay_);

}*/