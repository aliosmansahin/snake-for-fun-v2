#include "ConsoleManager.h"

#include "Event.h"

#include <thread>
#include <sstream>

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

	Event::SetSetOptionsEvent([&](int mapSize, int snakeSpeed) {
		std::lock_guard<std::mutex> lock(consoleMutex);

		mapSizeToShow = mapSize;
		snakeSpeedToShow = snakeSpeed;
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
	else if (input == 2) {
		ShowOptionsMenu();
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
	else if (input == 2) {
		ShowOptionsMenu();
	}
}

void ConsoleManager::ShowOptionsMenu()
{
	do {

		Clear();

		std::cout << "***** Options *****" << std::endl;

		std::cout << "Select options to modify: (current), or Back - 0" << std::endl;

		std::ostringstream oss;
		oss << "Map Size " << "(" << mapSizeToShow << ") - 1" << ", " << "Snake Speed " << "(" << snakeSpeedToShow << ") - 2";

		int input = ReadInput<int>("Enter", oss.str(), [](int test) {
			return (test == 0 || test == 1 || test == 2);
			});

		if (input == 0) {
			Event::GameOverEvent(); // To trigger game to start all entities from scratch, also returns the main menu
			break;
		}
		else if (input == 1) {
			int input = ReadInput<int>("Enter Map Size", "Between 20 - 128 and must divide 640", [](int test) {
				if (test < 20 || test > 128)
					return false;

				if (640 % test != 0) //TODO: hardcoded
					return false;

				return true;
				});

			mapSizeToShow = input;
			Event::UpdateMapSizeEvent(input);
		}
		else if (input == 2) {
			int input = ReadInput<int>("Enter Snake Speed", "Between 1 - 10... or 999", [](int test) {
				if (test == 999)
					return true;

				if (test >= 1 && test <= 10)
					return true;

				return false;
				});

			snakeSpeedToShow = input;
			Event::UpdateSnakeSpeedEvent(input);
		}
	} while (true);
}

void ConsoleManager::Clear()
{
	std::cout << "\x1b[2J\x1b[H" << std::flush;
}