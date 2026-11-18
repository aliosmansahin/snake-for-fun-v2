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

public:
	void Update();
	void Draw();

public:
	void UpdateProjectionMatrix();

public:
	void DrawTiles();

private:
	std::shared_ptr<GameStateBase> currentGameState;
	std::shared_ptr<Snake> snake;

	std::shared_ptr<Square> square;

	std::shared_ptr<Shader> shader;

private:
	int squareCount;
	int squareSize;
};