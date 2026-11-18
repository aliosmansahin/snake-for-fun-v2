#pragma once

#include "GameStateBase.h"

class GameOverState : public GameStateBase {
public:
	void Update(const Window& window, GameObjects gameObjects) override final;
	GameState GetGameState() override { return GameState::GAME_OVER; }
};