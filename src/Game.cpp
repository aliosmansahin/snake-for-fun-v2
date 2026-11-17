#include "Game.h"

#include "GameOverState.h"

Game::Game()
{
	currentGameState = std::make_shared<GameOverState>();
}

Game::~Game()
{}

void Game::Run(const Window& window)
{
	while (!window.ShouldClose()) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Update and draw */
		Update();
		Draw();

		window.Update();
	}
}

void Game::Update()
{
	currentGameState->Update({});
}

void Game::Draw()
{
	
}
