#pragma once

#include <functional>

enum class Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class Coord {
public:
	Coord() {
		this->x = 0;
		this->y = 0;
	}

	Coord(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Coord(int x, int y, int minX, int maxX, int minY, int maxY) {
		this->x = x;
		this->y = y;
		this->minX = minX;
		this->maxX = maxX;
		this->minY = minY;
		this->maxY = maxY;
	}

public:
	void Move(Direction direction) {
		switch (direction) {
		case Direction::LEFT:
			x--;
			break;
		case Direction::RIGHT:
			x++;
			break;
		case Direction::UP:
			y--;
			break;
		case Direction::DOWN:
			y++;
			break;
		}

		CheckBoundries();
	}

public:
	bool operator==(const Coord& other) const {
		return x == other.x && y == other.y;
	}

public:
	int GetX() const { return x; }
	int GetY() const { return y; }

private:
	void CheckBoundries() {
		if (x < minX)
			x = maxX;
		else if (x > maxX)
			x = minX;
		else if (y < minY)
			y = maxY;
		else if (y > maxY)
			y = minY;
	}

private:
	int x, y;

	int minX, maxX, minY, maxY;
};

namespace std {
	template <>
	struct hash<Coord> {
		std::size_t operator()(const Coord& coord) const noexcept {
			std::size_t h1 = std::hash<int>{}(coord.GetX());
			std::size_t h2 = std::hash<int>{}(coord.GetY());
			return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
		}
	};
}
