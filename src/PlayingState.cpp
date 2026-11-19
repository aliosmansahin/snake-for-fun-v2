#include "PlayingState.h"

#include "Event.h"

void PlayingState::Update(const Window& window, GameObjects gameObjects)
{
	gameObjects.snake->Update(window);

	if (gameObjects.snake->GetHead() == gameObjects.apple->GetCoord())
		Event::AppleBiteEvent();
}
