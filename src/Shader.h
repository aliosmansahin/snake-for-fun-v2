#pragma once

typedef int GLint; // No need to include glad here, just redefine GLint

class Shader {
public:
	Shader();
	~Shader();

	void Use();

public:
	void SetProjectionMatrix(float mat[4][4]);
	void SetModelMatrix(float mat[4][4]);
	void SetColorVector(float r, float g, float b);
	
private:
	unsigned int vertexShader, fragmentShader, shaderProgram;

private:
	GLint uniformProjectionMatrixLocation;
	GLint uniformModelMatrixLocation;
	GLint uniformColorLocation;
};