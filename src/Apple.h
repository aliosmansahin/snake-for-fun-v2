#pragma once

#include <memory>
#include <unordered_set>

#include "Square.h"
#include "Shader.h"

#include "Util.h"

class Apple {
public:
	Apple(int squareCount, const std::unordered_set<Coord>& notAllowed); // Randomly
	Apple(Coord coord);
	~Apple() = default;

public:
	void Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader);

	void Reset(Coord coord);

public:
	const Coord& GetCoord() const { return coord; }

private:
	Coord coord;
};