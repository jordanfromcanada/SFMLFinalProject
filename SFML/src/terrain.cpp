//
//  terrain.cpp

#include "terrain.hpp"

// Default constructor
Terrain::Terrain(){}

// populate array of points for the terrain
sf::VertexArray Terrain::get_terrain_points(){
    
    srand(time(NULL)); // random number generator seed
    sf::VertexArray vertexPoints(sf::LineStrip, 1200);
    int y = 600;
    int x = 0;
    int i = 0;
    int r;
    while (i < 1200) // array contains 1200 sequential x-coordinates
    {
      r = rand() % 10+1;
      if (r % 5 == 0)
      {
          if (1200 - i > 20)
            {for (int j = 0; j < 20; j++)
            {
            x += 1;
            y += 0;
            vertexPoints[i].position = sf::Vector2f(x, y);
            i++;
            }}
      }
      else
      {
        x += 1;
        y += ((rand() % 3) - 1) * 20; // also vary the multiplier of y to change terrain
        vertexPoints[i].position = sf::Vector2f(x, y);
        i++;
      }
    }
    return vertexPoints;
  }
