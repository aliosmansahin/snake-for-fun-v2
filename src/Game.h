#pragma once

#include <memory>

#include "Window.h"

#include "GameStateBase.h"

#include "Square.h"

#include "Shader.h"

class Game {
public:
	Game();
	~Game();

public:
	void Run(const Window& window);

	void Update();
	void Draw();

	void UpdateProjectionMatrix();

private:
	std::shared_ptr<GameStateBase> currentGameState;
	std::shared_ptr<Snake> snake;

	std::shared_ptr<Square> square;

	std::shared_ptr<Shader> shader;

private:
	int squareCount;
	int squareSize;
};