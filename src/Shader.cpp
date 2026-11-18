#include "Shader.h"

#include <glad/glad.h>
#include <fstream>
#include <sstream>

Shader::Shader()
{
    /* Vertex Shader */
    {
        std::ifstream vertexShaderFile("shader/vertexshader.glsl");
        if (!vertexShaderFile.is_open())
            throw std::runtime_error("Vertex shader file not found");

        std::ostringstream buffer;
        buffer << vertexShaderFile.rdbuf();
        const std::string vertexShaderStr = buffer.str();
        const char* vertexShaderSource = vertexShaderStr.c_str();

        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
    }

    /* Fragment Shader */
    {
        std::ifstream fragmentShaderFile("shader/fragmentshader.glsl");
        if (!fragmentShaderFile.is_open())
            throw std::runtime_error("Fragment shader file not found");

        std::ostringstream buffer;
        buffer << fragmentShaderFile.rdbuf();
        const std::string fragmentShaderStr = buffer.str();
        const char* fragmentShaderSource = fragmentShaderStr.c_str();

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
    }

    // Shader Program
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    Use();

    uniformProjectionMatrixLocation = glGetUniformLocation(shaderProgram, "projection");
    uniformModelMatrixLocation = glGetUniformLocation(shaderProgram, "model");
}

Shader::~Shader()
{
    glDeleteProgram(shaderProgram);
}

void Shader::Use()
{
    glUseProgram(shaderProgram);
}

void Shader::SetProjectionMatrix(float mat[4][4])
{
    glUniformMatrix4fv(uniformProjectionMatrixLocation, 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetModelMatrix(float mat[4][4])
{
    glUniformMatrix4fv(uniformModelMatrixLocation, 1, GL_FALSE, &mat[0][0]);
}
