#pragma once

#include <memory>

#include "Window.h"

#include "GameStateBase.h"

class Game {
public:
	Game();
	~Game();

public:
	void Run(const Window& window);

	void Update();
	void Draw();

private:
	std::shared_ptr<GameStateBase> currentGameState;
};