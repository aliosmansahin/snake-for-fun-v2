#pragma once

#include <memory>

#include "Square.h"
#include "Shader.h"

class Apple {
public:
	Apple(int squareCount); // Randomly
	Apple(int x, int y);
	~Apple();

public:
	void Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader);

	void Reset(int x, int y);

public:
	int GetX() { return x; }
	int GetY() { return y; }

private:
	int x, y;
};