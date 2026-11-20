#include "Event.h"

CallbackList<> Event::startGameCallback   = {};
CallbackList<> Event::gameOverCallback    = {};
CallbackList<> Event::appleBiteCallback   = {};
CallbackList<int> Event::addScoreCallback = {};
CallbackList<int> Event::updateMapSizeCallback = {};
CallbackList<int> Event::updateSnakeSpeedCallback = {};
CallbackList<int, int> Event::setOptionsCallback = {};
CallbackList<> Event::pauseGameCallback = {};
CallbackList<> Event::resumeGameCallback = {};

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

/* Invoked when game is over or initial menu */
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

void Event::UpdateMapSizeEvent(int newMapSize)
{
	for (const auto& callback : updateMapSizeCallback)
		callback(newMapSize);
}

void Event::SetUpdateMapSizeEvent(std::function<void(int)> callback)
{
	updateMapSizeCallback.emplace_back(callback);
}

void Event::UpdateSnakeSpeedEvent(int newSnakeSpeed)
{
	for (const auto& callback : updateSnakeSpeedCallback)
		callback(newSnakeSpeed);
}

void Event::SetUpdateSnakeSpeedEvent(std::function<void(int)> callback)
{
	updateSnakeSpeedCallback.emplace_back(callback);
}

void Event::SetOptionsEvent(int mapSize, int snakeSpeed)
{
	for (const auto& callback : setOptionsCallback)
		callback(mapSize, snakeSpeed);
}

void Event::SetSetOptionsEvent(std::function<void(int, int)> callback)
{
	setOptionsCallback.emplace_back(callback);
}

void Event::PauseGameEvent()
{
	for (const auto& callback : pauseGameCallback)
		callback();
}

void Event::SetPauseGameEvent(std::function<void()> callback)
{
	pauseGameCallback.emplace_back(callback);
}

void Event::ResumeGameEvent()
{
	for (const auto& callback : resumeGameCallback)
		callback();
}

void Event::SetResumeGameEvent(std::function<void()> callback)
{
	resumeGameCallback.emplace_back(callback);
}