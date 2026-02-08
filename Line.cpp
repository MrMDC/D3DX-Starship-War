#include "Line.h"

void Line::initLine(int verticeNum, D3DXVECTOR2 vertices[], D3DCOLOR color)
{
    //Initialize the line variables
    this->verticeNum = verticeNum;
    this->vertices = new D3DXVECTOR2[verticeNum];

    for (int i = 0; i < verticeNum; i++) {
        this->vertices[i] = vertices[i];
    }

    this->color = color;
}

void Line::setColor()
{
    this->color = color;
}

void Line::render()
{
    //Draw the lines
    d3dManager->getLineBrush()->Begin();
    d3dManager->getLineBrush()->Draw(vertices, verticeNum, color);
    d3dManager->getLineBrush()->End();
}

void Line::cleanup()
{
}

void Line::createStar(D3DXVECTOR2 position, int size)
{
    verticeNum = 11; // Set the number of vertices
    vertices = new D3DXVECTOR2[verticeNum];
    color = D3DCOLOR_XRGB(255, 232, 102);
    int halfSize = size / 2;

    // Define the vertices of a star relative to the center point (position.x, position.y)
    float angleIncrement = 72.0f; // Angle increment for each point (360 degrees / 5 points = 72 degrees per point)
    float currentAngle = -90.0f; // Start at the top point
    for (int i = 0; i < verticeNum; i++) {
        float radius = (i % 2 == 0) ? halfSize : (halfSize / 2); // Alternate between outer and inner points
        float x = position.x + radius * cos(currentAngle * (3.14159265f / 180.0f));
        float y = position.y + radius * sin(currentAngle * (3.14159265f / 180.0f));
        vertices[i] = D3DXVECTOR2(x, y);
        currentAngle += angleIncrement;
    }
}

Line::Line()
{
}

Line::~Line()
{
    cleanup();
}
