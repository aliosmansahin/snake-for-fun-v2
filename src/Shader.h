#pragma once

class Shader {
public:
	Shader();
	~Shader();

	void Use();
private:
	unsigned int vertexShader, fragmentShader, shaderProgram;
};