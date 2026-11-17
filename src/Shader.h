#pragma once

class Shader {
public:
	Shader();
	~Shader();

	void Use();

	unsigned int GetID() const { return shaderProgram; }
private:
	unsigned int vertexShader, fragmentShader, shaderProgram;
};