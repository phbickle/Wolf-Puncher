#pragma once


#include "SDL.h"
#include "SDL_image.h"
#include "MathUtils.h"
#include "Sprite.h"


class Game
{
protected:
	SDL_Surface* pDisplay_; //main frame buffer
	SDL_Surface* pTestImage_;
	SDL_Surface* p2TestImage_;


	const Uint16 SCREEN_WIDTH;
	const Uint16 SCREEN_HEIGHT;


	void clearBackBuffer();
	void handleEvent(const SDL_Event& newEvent);

	virtual void loadAssets() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw();
	virtual void onKeyDown(Uint16 key);
	virtual void onKeyUp(Uint16 key);

	//temp variables
	//Vec2 velocity_, pos_;
	bool running_;
	Uint32 clearColour_;


	//const int w = 50;
	//const int h = 50;

public:
	Game();
	~Game();

	int moveDown = 1;
	//const int imageVY = 1;
	//const int initialVY = 0;
	void InitSDL();
	//void InitTestImage();
	void Run();
	void Clean();

};

