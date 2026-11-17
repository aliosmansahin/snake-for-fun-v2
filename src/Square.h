#pragma once

#include <glad/glad.h>

class Square {
public:
	Square();
	~Square();

public:
	void Draw();

private:
	unsigned int VBO, VAO, EBO;
};