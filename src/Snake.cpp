#include "Snake.h"

#include "Event.h"

Snake::Snake(int squareCount)
{
	/* Set initial values - reset snake */
	this->squareCount = squareCount;
	moveCooldown = 0.1;
	moveLastTime = 0.0;
}

Snake::~Snake()
{}

void Snake::Update(const Window& window)
{
	if (window.CheckKey(GLFW_KEY_W) && direction != Direction::DOWN) {
		directionBuffer = Direction::UP;
	}
	else if (window.CheckKey(GLFW_KEY_S) && direction != Direction::UP) {
		directionBuffer = Direction::DOWN;
	}
	else if (window.CheckKey(GLFW_KEY_A) && direction != Direction::RIGHT) {
		directionBuffer = Direction::LEFT;
	}
	else if (window.CheckKey(GLFW_KEY_D) && direction != Direction::LEFT) {
		directionBuffer = Direction::RIGHT;
	}

	double currentTime = window.GetTime();
	if (currentTime < moveLastTime + moveCooldown) {
		return;
	}
	moveLastTime = currentTime;
	
	direction = directionBuffer;

	Coord oldHead = head;

	switch (direction) {
	case Direction::LEFT:
		head.x--;
		break;
	case Direction::RIGHT:
		head.x++;
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

	if (tailForCheck.find(std::to_string(head.x) + "-" + std::to_string(head.y)) != tailForCheck.end()) {
		Event::GameOverEvent();
		return;
	}

	tailForCheck.insert(std::to_string(oldHead.x) + "-" + std::to_string(oldHead.y));
	tail.push_back(oldHead);

	if (tail.size() > maxTail) {
		Coord last = tail[0];
		tailForCheck.erase(std::to_string(last.x) + "-" + std::to_string(last.y));
		tail.erase(tail.begin());
	}
}

void Snake::Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader)
{
	for (int i = 0; i < tail.size(); ++i) {
		auto sq = tail[i];
		square->Draw(sq.x, sq.y, 0.1f, 0.1f, 0.1f, shader);
	}

	/* Head */
	square->Draw(head.x, head.y, 0.2f, 0.2f, 0.2f, shader);
}

void Snake::Reset()
{
	head = { 12, 12 };
	maxTail = 5;
	direction = Direction::RIGHT;
	directionBuffer = Direction::RIGHT;
	tail.clear();
	tailForCheck.clear();
}
