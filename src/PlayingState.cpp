#include "PlayingState.h"

void PlayingState::Update(const Window& window, GameObjects gameObjects)
{
	gameObjects.snake->Update(window);
}
