#pragma once

#include <vector>
#include <memory>

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

private:
	std::vector<Coord> tail;
	Coord head;
	Direction direction;
	int maxTail;

private:
	int squareCount;
};