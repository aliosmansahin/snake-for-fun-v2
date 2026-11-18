#include "Apple.h"

#include <cstdlib>
#include <ctime>

Apple::Apple(int squareCount)
{
	std::srand(std::time(nullptr));

	this->x = std::rand() % squareCount;
	this->y = std::rand() % squareCount;
}

Apple::Apple(int x, int y)
{
	Reset(x, y);
}

Apple::~Apple()
{}

void Apple::Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader)
{
	square->Draw(x, y, 0.7, 0.1, 0.1, shader);
}

void Apple::Reset(int x, int y)
{
	this->x = x;
	this->y = y;
}
