//
//  lander.cpp

#include "lander.hpp"

// return an array of (x, y) points then window.draw(<the array of points>) to create terrain
sf::VertexArray get_terrain_points()
{
    sf::VertexArray vertexPoints(sf::LineStrip, 1200);
    int y = 600;
    int x = 1;
    for (int i = 0; i < 1200; i++)
    {
        vertexPoints[i].position = sf::Vector2f(x, y);
        x += 10; // to generate new terrain each time, vary x between 10 and 50
        if (i % 5 == 0)
        {
            y += 0;
        }
        else
        {
        y += ((rand() % 3) - 1) * 50; // also vary the multiplier of y to change terrain
        }
    }
    return vertexPoints;
}

// default constructor
//Lander::Lander() {
//    // TODO: set sprite texture, position, color in class constructor
//}
