#pragma once

#include <functional>

class Event {
public:
	static void StartGameEvent();

	static void SetStartGameEvent(std::function<void()> callback);

	static void GameOverEvent();

	static void SetGameOverEvent(std::function<void()> callback);

public:
	static std::function<void()> startGameCallback;
	static std::function<void()> gameOverCallback;
};