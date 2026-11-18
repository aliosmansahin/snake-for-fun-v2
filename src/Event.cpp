#include "Event.h"

std::function<void()> Event::startGameCallback = []() {};
std::function<void()> Event::gameOverCallback = []() {};
std::function<void()> Event::appleBiteCallback  = []() {};

void Event::StartGameEvent()
{
	startGameCallback();
}

void Event::SetStartGameEvent(std::function<void()> callback)
{
	startGameCallback = callback;
}

void Event::GameOverEvent()
{
	gameOverCallback();
}

void Event::SetGameOverEvent(std::function<void()> callback)
{
	gameOverCallback = callback;
}

void Event::AppleBiteEvent()
{
	appleBiteCallback();
}

void Event::SetAppleBiteEvent(std::function<void()> callback)
{
	appleBiteCallback = callback;
}
