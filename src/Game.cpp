#include "Game.h"

Game::Game()
{
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
{}

void Game::Draw()
{}
