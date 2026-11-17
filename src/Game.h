#pragma once

#include "Window.h"

class Game {
public:
	Game();
	~Game();

public:
	void Run(const Window& window);

	void Update();
	void Draw();

private:
	
};