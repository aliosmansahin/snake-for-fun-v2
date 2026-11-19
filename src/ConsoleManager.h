#pragma once

#include <iostream>
#include <functional>
#include <mutex>
#include <ios>
#include <limits>
#include <string>

class ConsoleManager {
public:
	ConsoleManager();

public:
	void ShowMainMenu();
	void ShowPlayingMenu();
	void ShowGameOverMenu();
	void ShowOptionsMenu();

	void Clear();

public:
	void SetScore(int newScore) { scoreToShow = newScore; }
	
public:
	/* The rule callback is to test got user input, if it returns false, the method will get a new input */
	template <typename T>
	T ReadInput(const std::string& label, const std::string& ruleText = "", std::function<bool(T)> ruleCallback = [](T test) {return true; }) {
		T t;

		if(!ruleText.empty())
			std::cout << ruleText << std::endl;

		do {
			std::cout << label << ": ";

			if(!(std::cin >> t))
			{
				std::cout << "Error occurred while reading the user input!" << std::endl;
				std::cout << "Please try again..." << std::endl;

				std::cin.clear();

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				continue;
			}

			if (!ruleCallback(t)) {
				std::cout << "Please enter one of options that are indicated!" << std::endl;
				continue;
			}

			break;
		} while (true);

		return t;
	}
	
private:
	std::mutex consoleMutex;

private:
	int scoreToShow;
	int mapSizeToShow;
	int snakeSpeedToShow;
};