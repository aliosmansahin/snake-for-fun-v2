#pragma once

#include <glad/glad.h>

#include "Shader.h"

#include "Util.h"

#include <memory>

class Square {
public:
	Square(int squareSize);
	~Square();

public:
	void Draw(const Coord& coord, float r, float g, float b, std::shared_ptr<Shader> shader);

private:
	void UpdateTransformMatrix(const Coord& coord, const std::shared_ptr<Shader> shader);
	void UpdateColor(float r, float g, float b, const std::shared_ptr<Shader> shader);

private:
	unsigned int VBO, VAO, EBO;

private:
	int squareSize;
};