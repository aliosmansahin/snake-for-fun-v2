#pragma once

#include <deque>
#include <memory>
#include <unordered_set>

#include "Shader.h"
#include "Square.h"
#include "Window.h"

#include "Util.h"

class Snake {
public:
	Snake(int squareCount, int snakeSpeed);
	~Snake();

public:
	void Update(const Window& window);
	void Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader);

	void AddTail() { maxTail++; }

private:
	void SetSpeed(int snakeSpeed);

public:
	const Coord& GetHead() const { return head; }
	const std::unordered_set<Coord>& GetTail() const { return tailForCheck; }

private:
	std::deque<Coord> tail; // For push front, pop back, head is not included
	std::unordered_set<Coord> tailForCheck; // Head is not included
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