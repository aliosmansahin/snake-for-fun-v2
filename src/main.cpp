#include "Window.h"
#include "Game.h"
#include "ConsoleManager.h"

int main() {
	Window window;
	ConsoleManager console;
	Game game;

	game.Run(window, console);

	return 0;
}