#include "Apple.h"

#include <cstdlib>
#include <ctime>
#include <string>

Apple::Apple(int squareCount, const std::unordered_set<Coord>& notAllowed)
{
	std::srand(std::time(nullptr));

	do {
		coord = Coord(std::rand() % squareCount, std::rand() % squareCount);
	} while (notAllowed.find(coord) != notAllowed.end());
}

Apple::Apple(Coord coord)
{
	this->coord = coord;
}

void Apple::Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader)
{
	square->Draw(coord, 0.7, 0.1, 0.1, shader);
}
