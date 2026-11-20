#include "Game.h"

#include "GameOverState.h"
#include "PlayingState.h"

#include "Event.h"

Game::Game()
{
	shader = std::make_shared<Shader>();
	score = 0;
	snakeSpeed = 0.1;
	gamePaused = true;

	Event::SetStartGameEvent([&]() {
		currentGameState = std::make_shared<PlayingState>();
		gamePaused = false;
		score = 0;
		});

	Event::SetGameOverEvent([&]() {
		currentGameState = std::make_shared<GameOverState>();
		snake = std::make_shared<Snake>(squareCount, snakeSpeed);
		apple = std::make_shared<Apple>(Coord{ 5, 5 });
		gamePaused = true;
		});

	Event::SetAppleBiteEvent([&]() {
		apple = std::make_shared<Apple>(squareCount, snake->GetTail());
		snake->AddTail();

		Event::AddScoreEvent(++score);
		});

	Event::SetUpdateMapSizeEvent([&](int mapSize) {
		squareCount = mapSize;
		squareSize = 640 / squareCount;
		square = std::make_shared<Square>(squareSize);
		});

	Event::SetUpdateSnakeSpeedEvent([&](int snakeSpeed) {
		this->snakeSpeed = snakeSpeed;
		});

	Event::SetSetOptionsEvent([](int mapSize, int snakeSpeed) {
		Event::UpdateMapSizeEvent(mapSize);
		Event::UpdateSnakeSpeedEvent(snakeSpeed);
		});

	Event::SetPauseGameEvent([&]() {
		gamePaused = true;
		});

	Event::SetResumeGameEvent([&]() {
		gamePaused = false;
		});

	Event::SetOptionsEvent(20, 5);

	Event::GameOverEvent(); // Start with gameover
}

Game::~Game()
{}

void Game::Run(const Window& window, const ConsoleManager& console)
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
	if(!gamePaused)
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

			square->Draw({x, y}, r, g, b, shader);
		}
	}
}
