#include "GameOverState.h"

#include "Event.h"

void GameOverState::Update(const Window& window, GameObjects gameObjects)
{
	if (window.CheckKey(GLFW_KEY_SPACE)) {
		Event::StartGameEvent();
	}
}
