#pragma once

#include <functional>
#include <vector>

template<typename... Args>
using CallbackList = std::vector<std::function<void(Args...)>>;

class Event {
public:
	static void StartGameEvent();

	static void SetStartGameEvent(std::function<void()> callback);

	static void GameOverEvent();

	static void SetGameOverEvent(std::function<void()> callback);

	static void AppleBiteEvent();

	static void SetAppleBiteEvent(std::function<void()> callback);

	static void AddScoreEvent(int newScore);

	static void SetAddScoreEvent(std::function<void(int)> callback);

	static void UpdateMapSizeEvent(int newMapSize);

	static void SetUpdateMapSizeEvent(std::function<void(int)> callback);

	static void UpdateSnakeSpeedEvent(int newSnakeSpeed);

	static void SetUpdateSnakeSpeedEvent(std::function<void(int)> callback);

public:
	static CallbackList<> startGameCallback;
	static CallbackList<> gameOverCallback;
	static CallbackList<> appleBiteCallback;
	static CallbackList<int> addScoreCallback; // Has score parameter
	static CallbackList<int> updateMapSizeCallback; // Has map size parameter
	static CallbackList<int> updateSnakeSpeedCallback; // Has snake speed parameter
};