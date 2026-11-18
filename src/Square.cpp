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

void Square::Draw(int x, int y, std::shared_ptr<Shader> shader)
{
    glBindVertexArray(VAO);

    UpdateTransformMatrix(x, y, shader);
    
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

    GLint modelLoc = glGetUniformLocation(shader->GetID(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelMatrix[0][0]);
}
