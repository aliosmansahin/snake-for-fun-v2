#pragma once

#include <functional>

class Event {
public:
	static void StartGameEvent();

	static void SetStartGameEvent(std::function<void()> callback);

public:
	static std::function<void()> startGameCallback;
};