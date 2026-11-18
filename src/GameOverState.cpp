#include "GameOverState.h"

#include "Event.h"

void GameOverState::Update(const Window& window, GameObjects gameObjects)
{
	if (!gameSet) {
		gameObjects.snake->Reset();
		gameObjects.apple->Reset(5, 5);
		gameSet = true;
	}
	if (window.CheckKey(GLFW_KEY_SPACE)) {
		Event::StartGameEvent();
	}
}
