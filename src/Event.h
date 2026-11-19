#pragma once

#include <functional>
#include <unordered_set>

typedef std::vector<std::function<void()>> CallbackList;

class Event {
public:
	static void StartGameEvent();

	static void SetStartGameEvent(std::function<void()> callback);

	static void GameOverEvent();

	static void SetGameOverEvent(std::function<void()> callback);

	static void AppleBiteEvent();

	static void SetAppleBiteEvent(std::function<void()> callback);

public:
	static CallbackList startGameCallback;
	static CallbackList gameOverCallback;
	static CallbackList appleBiteCallback;
};