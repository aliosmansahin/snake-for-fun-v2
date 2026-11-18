#include "Snake.h"

Snake::Snake(int squareCount)
{
	/* Set initial values - reset snake */
	head = { 5, 5 };
	maxTail = 5;
	direction = Direction::LEFT;
	tail.push_back(head);
	this->squareCount = squareCount;
}

Snake::~Snake()
{}

void Snake::Update(const Window& window)
{
	if (window.CheckKey(GLFW_KEY_W) && direction != Direction::DOWN) {
		direction = Direction::UP;
	}
	else if (window.CheckKey(GLFW_KEY_S) && direction != Direction::UP) {
		direction = Direction::DOWN;
	}
	else if (window.CheckKey(GLFW_KEY_A) && direction != Direction::RIGHT) {
		direction = Direction::LEFT;
	}
	else if (window.CheckKey(GLFW_KEY_D) && direction != Direction::LEFT) {
		direction = Direction::RIGHT;
	}

	switch (direction) {
	case Direction::LEFT:
		head.x++;
		break;
	case Direction::RIGHT:
		head.x--;
		break;
	case Direction::UP:
		head.y--;
		break;
	case Direction::DOWN:
		head.y++;
		break;
	}

	if (head.x < 0)
		head.x = squareCount - 1;
	else if (head.x > squareCount - 1)
		head.x = 0;
	else if (head.y < 0)
		head.y = squareCount - 1;
	else if (head.y > squareCount - 1)
		head.y = 0;

	tail.push_back(head);

	if (tail.size() > maxTail)
		tail.erase(tail.begin());
}

void Snake::Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader)
{
	for (const auto& sq : tail) {
		square->Draw(sq.x, sq.y, 0.1f, 0.1f, 0.1f, shader);
	}
}
