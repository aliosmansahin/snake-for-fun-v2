#include "Game.h"

#include "GameOverState.h"
#include "PlayingState.h"

#include "Event.h"

Game::Game()
{
	shader = std::make_shared<Shader>();
	currentGameState = std::make_shared<GameOverState>();
	squareCount = 20;
	squareSize = 640 / squareCount;
	snake = std::make_shared<Snake>(squareCount);
	apple = std::make_shared<Apple>(5, 5);

	square = std::make_shared<Square>(squareSize);

	Event::SetStartGameEvent([&]() {
		currentGameState = std::make_shared<PlayingState>();
		});

	Event::SetGameOverEvent([&]() {
		currentGameState = std::make_shared<GameOverState>();
		});

	Event::SetAppleBiteEvent([&]() {
		apple = std::make_shared<Apple>(squareCount);
		snake->AddTail();
		});
}

Game::~Game()
{}

void Game::Run(const Window& window)
{
	while (!window.ShouldClose()) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Update and draw */
		Update(window);
		Draw();

		window.Update();
	}
}

void Game::Update(const Window& window)
{
	currentGameState->Update(window, {snake, apple});
}

void Game::Draw()
{
	shader->Use();

	UpdateProjectionMatrix();

	DrawTiles();

	snake->Draw(square, shader);
	apple->Draw(square, shader);
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

void Game::DrawTiles()
{
	for (int y = 0; y < squareCount; ++y) {
		for (int x = 0; x < squareCount; ++x) {
			float r, g, b;

			if ((x + y) % 2 == 0) {
				r = 0.0f;
				g = 0.8f;
				b = 0.2f;
			}
			else {
				r = 0.0f;
				g = 0.6f;
				b = 0.4f;
			}

			square->Draw(x, y, r, g, b, shader);
		}
	}
}
