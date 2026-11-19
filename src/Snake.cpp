#include "Snake.h"

#include "Event.h"

Snake::Snake(int squareCount, int snakeSpeed)
{
	/* Set initial values - reset snake */
	this->squareCount = squareCount;
	SetSpeed(snakeSpeed);
	moveLastTime = 0.0;

	head = Coord(12, 12, 0, squareCount - 1, 0, squareCount - 1);
	maxTail = 4;
	direction = Direction::RIGHT;
	directionBuffer = Direction::RIGHT;
	tail.clear();
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

	head.Move(direction);

	if (tailForCheck.find(head) != tailForCheck.end()) {
		Event::GameOverEvent();
		return;
	}

	tailForCheck.insert(oldHead);
	tail.push_front(oldHead);

	if (tail.size() > maxTail) {
		Coord& coord = tail.back();
		tailForCheck.erase(coord);
		tail.pop_back();
	}
}

void Snake::Draw(const std::shared_ptr<Square> square, const std::shared_ptr<Shader> shader)
{
	for (const auto& sq : tail) {
		square->Draw(sq, 0.1f, 0.1f, 0.1f, shader);
	}

	/* Head */
	square->Draw(head, 0.2f, 0.2f, 0.2f, shader);
}

void Snake::SetSpeed(int speed)
{
	/* Set move cooldown */

	if (speed == 999) {
		moveCooldown = 0.0001; // Speed, I am speed
		return;
	}

	moveCooldown = static_cast<double>(11 - speed) / 100.0;
}
