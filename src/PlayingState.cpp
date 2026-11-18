#include "PlayingState.h"

#include "Event.h"

void PlayingState::Update(const Window& window, GameObjects gameObjects)
{
	gameObjects.snake->Update(window);

	if (gameObjects.snake->GetX() == gameObjects.apple->GetX() &&
		gameObjects.snake->GetY() == gameObjects.apple->GetY())
		Event::AppleBiteEvent();
}
