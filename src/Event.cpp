#include "Event.h"

std::function<void()> Event::startGameCallback = []() {};

void Event::StartGameEvent()
{
	startGameCallback();
}

void Event::SetStartGameEvent(std::function<void()> callback)
{
	startGameCallback = callback;
}
