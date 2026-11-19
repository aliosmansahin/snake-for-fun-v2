#include "ConsoleManager.h"

#include "Event.h"

#include <thread>

ConsoleManager::ConsoleManager()
{
	Event::SetGameOverEvent([&]() {
		std::thread t([&]() {
			ShowMainMenu();
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

void ConsoleManager::Clear()
{
	std::cout << "\x1b[2J\x1b[H" << std::flush;
}