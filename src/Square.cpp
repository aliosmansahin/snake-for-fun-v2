#include "Square.h"

Square::Square(int squareSize): squareSize(squareSize)
{
    float vertices[] = {
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f,
    };
    unsigned int indices[] = {
        2, 1, 0,
        2, 3, 0
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Square::~Square()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

/*
    x, y: in-tile coordinates
    r, g, b: 0 -> 1 colors
*/
void Square::Draw(int x, int y, float r, float g, float b, std::shared_ptr<Shader> shader)
{
    glBindVertexArray(VAO);

    UpdateTransformMatrix(x, y, shader);
    UpdateColor(r, g, b, shader);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Square::UpdateTransformMatrix(int x, int y, std::shared_ptr<Shader> shader)
{
    float modelMatrix[4][4] = {
           {static_cast<float>(squareSize), 0.0f,       0.0f, 0.0f},
           {0.0f,       static_cast<float>(squareSize), 0.0f, 0.0f},
           {0.0f,       0.0f,       1.0f, 0.0f},
           {static_cast<float>(x * squareSize), static_cast<float>(y * squareSize), 0.0f, 1.0f},
    };

    shader->SetModelMatrix(modelMatrix);
}

void Square::UpdateColor(float r, float g, float b, const std::shared_ptr<Shader> shader)
{
    shader->SetColorVector(r, g, b);
}
