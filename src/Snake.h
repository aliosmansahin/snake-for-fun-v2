#pragma once

#include <vector>
#include <memory>
#include <unordered_set>
#include <string>

#include "Shader.h"
#include "Square.h"
#include "Window.h"

struct Coord {
	int x, y;
};

enum class Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class Snake {
public:
	Snake(int squareCount);
	~Snake();

public:
	void Update(const Window& window);
	void Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader);

	void Reset();
	void AddTail() { maxTail++; }

public:
	int GetX() { return head.x; }
	int GetY() { return head.y; }

private:
	std::vector<Coord> tail; // Head is included
	std::unordered_set<std::string> tailForCheck; // Head is not included
	Coord head;
	Direction direction;
	int maxTail;

private:
	int squareCount;

private:
	Direction directionBuffer;

private:
	double moveCooldown;
	double moveLastTime;
};