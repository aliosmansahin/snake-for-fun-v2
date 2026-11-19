#include "ConsoleManager.h"

#include "Event.h"

#include <thread>

ConsoleManager::ConsoleManager()
{
	scoreToShow = -1;

	Event::SetGameOverEvent([&]() {
		std::thread t([&]() {
			if (scoreToShow == -1)
				ShowMainMenu();
			else
				ShowGameOverMenu();
			});
		t.detach();
		});

	Event::SetStartGameEvent([&]() {
		scoreToShow = 0;
		std::thread t([&]() {
			ShowPlayingMenu();
			});
		t.detach();
		});

	Event::SetAddScoreEvent([&](int score) {
		scoreToShow = score;

		std::thread t([&]() {
			ShowPlayingMenu();
			});
		t.detach();
		});
}

void ConsoleManager::ShowMainMenu()
{
	std::lock_guard<std::mutex> lock(consoleMutex);

	Clear();

	std::cout << "***** SNAKE GAME *****" << std::endl;

	int input = ReadInput<int>("Enter", "Play - 1, Options - 2", [](int test) {
		return (test == 1 || test == 2);
		});

	if (input == 1) {
		Event::StartGameEvent();
	}
}

void ConsoleManager::ShowPlayingMenu()
{
	std::lock_guard<std::mutex> lock(consoleMutex);

	Clear();

	std::cout << "***** In Play *****" << std::endl;

	std::cout << "Score: " << scoreToShow;
}

void ConsoleManager::ShowGameOverMenu()
{
	std::lock_guard<std::mutex> lock(consoleMutex);

	Clear();

	std::cout << "***** Game Over *****" << std::endl;

	std::cout << "Score: " << scoreToShow << std::endl;

	int input = ReadInput<int>("Enter", "Play Again - 1, Options - 2", [](int test) {
		return (test == 1 || test == 2);
		});

	if (input == 1) {
		Event::StartGameEvent();
	}
}

void ConsoleManager::Clear()
{
	std::cout << "\x1b[2J\x1b[H" << std::flush;
}