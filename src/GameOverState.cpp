#include "GameOverState.h"

#include "Event.h"

void GameOverState::Update(const Window& window, GameObjects gameObjects)
{
	if (!gameSet) {
		gameObjects.snake->Reset();
		gameSet = true;
	}
	if (window.CheckKey(GLFW_KEY_SPACE)) {
		Event::StartGameEvent();
	}
}
