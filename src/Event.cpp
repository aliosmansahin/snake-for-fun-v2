#include "Event.h"

CallbackList<> Event::startGameCallback   = {};
CallbackList<> Event::gameOverCallback    = {};
CallbackList<> Event::appleBiteCallback   = {};
CallbackList<int> Event::addScoreCallback = {};

void Event::StartGameEvent()
{
	for(const auto& callback : startGameCallback)
		callback();
}

void Event::SetStartGameEvent(std::function<void()> callback)
{
	startGameCallback.emplace_back(callback);
}

void Event::GameOverEvent()
{
	for (const auto& callback : gameOverCallback)
		callback();
}

void Event::SetGameOverEvent(std::function<void()> callback)
{
	gameOverCallback.emplace_back(callback);
}

void Event::AppleBiteEvent()
{
	for (const auto& callback : appleBiteCallback)
		callback();
}

void Event::SetAppleBiteEvent(std::function<void()> callback)
{
	appleBiteCallback.emplace_back(callback);
}

void Event::AddScoreEvent(int newScore)
{
	for (const auto& callback : addScoreCallback)
		callback(newScore);
}

/* Invoked after the score has been increased */
void Event::SetAddScoreEvent(std::function<void(int)> callback)
{
	addScoreCallback.emplace_back(callback);
}
