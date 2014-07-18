#include "Game.h"
#include <iostream>

const Uint8 CLEAR_RED = 0;
const Uint8 CLEAR_GREEN = 0;
const Uint8 CLEAR_BLUE = 0;

Game::Game(void) :

pDisplay_(0),
//pTestImage_(0),
SCREEN_WIDTH(500),
SCREEN_HEIGHT(400),
running_(true)
{

}


Game::~Game()
{

}

void Game::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//c++ way:
		std::cerr << "Unable to init SDL: " << SDL_GetError;
		exit(1);
	}
	pDisplay_ = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	clearColour_ = SDL_MapRGB(pDisplay_->format, CLEAR_RED, CLEAR_GREEN, CLEAR_BLUE);
	loadAssets();
}

/*
void Game::InitTestImage()
{
pTestImage_ = IMG_Load("bearmangler.png");
pTestImage_ = SDL_DisplayFormat(pTestImage_);
p2TestImage_ = IMG_Load("nightSky.png");
p2TestImage_ = SDL_DisplayFormat(p2TestImage_);
}*/

void Game::Run()
{
	LARGE_INTEGER currTime, prevTime, frequency;
	float deltaTime = 0.0f;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&prevTime);

	SDL_Event newEvent;
	while (running_)
	{
		while (SDL_PollEvent(&newEvent))
		{
			handleEvent(newEvent);
		}
		QueryPerformanceCounter(&currTime);
		deltaTime = (float)(currTime.QuadPart - prevTime.QuadPart) /
			(float)frequency.QuadPart;
		prevTime = currTime;
		//test code,, move the test image based on input
		//pos_ = pos_ + velocity_;
		////////////////////////
		update(deltaTime);

		clearBackBuffer();
		draw();


	}

}

void Game::clearBackBuffer()
{
	SDL_FillRect(pDisplay_, &pDisplay_->clip_rect, clearColour_);


}

void Game::draw()
{
	SDL_Flip(pDisplay_);
}

void Game::Clean()
{
	SDL_Quit();
}

void Game::handleEvent(const SDL_Event& newEvent)
{//big or complex data passes references for efficiency
	switch (newEvent.type)
	{
	case SDL_QUIT:
		running_ = false;
		break;
	case SDL_KEYDOWN:
		onKeyDown(newEvent.key.keysym.sym);
		break;
	case SDL_KEYUP:
		onKeyUp(newEvent.key.keysym.sym);
		break;

	}
}

void Game::onKeyDown(Uint16 key)
{
	switch (key)
	{
	case SDLK_ESCAPE:
		running_ = false;
		break;
	case SDLK_UP:
		//inputDir_.y = -1.0f;
		break;

	case SDLK_DOWN:
		//inputDir_.y = 1.0f;
		break;

	case SDLK_RIGHT:
		//inputDir_.x = 1.0f;
		break;

	case SDLK_LEFT:
	//	inputDir_.x = -1.0f;
		break;
	}

}

void Game::onKeyUp(Uint16 key)
{

}