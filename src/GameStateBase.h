#pragma once

#include "Snake.h"

#include <memory>

enum class GameState {
	GAME_OVER,
	PLAYING,
};

struct GameObjects {
	std::shared_ptr<Snake> snake;
};

class GameStateBase {
public:
	virtual void Update(GameObjects gameObjects) = 0;
	virtual GameState GetGameState() = 0;
};