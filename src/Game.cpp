#include "Game.h"

#include "GameOverState.h"

Game::Game()
{
	shader = std::make_shared<Shader>();
	currentGameState = std::make_shared<GameOverState>();
	snake = std::make_shared<Snake>();
	squareCount = 10;
	squareSize = 640 / squareCount;

	square = std::make_shared<Square>(squareSize);
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
	currentGameState->Update({snake});
}

void Game::Draw()
{
	shader->Use();

	UpdateProjectionMatrix();

	square->Draw(0, 0, shader);
}

void Game::UpdateProjectionMatrix()
{
	float left = 0.0f;
	float right = static_cast<float>(640);
	float bottom = static_cast<float>(640); // TODO: Hardcoded, get it from the window
	float top = 0.0f;
	float zNear = -1.0f;
	float zFar = 1.0f;

	float proj[4][4] = {
		{2.0f / (right - left), 0.0f, 0.0f, 0.0f},
		{0.0f, 2.0f / (top - bottom), 0.0f, 0.0f},
		{0.0f, 0.0f, -2.0f / (zFar - zNear), 0.0f},
		{-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(zFar + zNear) / (zFar - zNear), 1.0f}
	};

	shader->SetProjectionMatrix(proj);
}
