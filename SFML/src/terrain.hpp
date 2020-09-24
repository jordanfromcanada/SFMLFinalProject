//
//  terrain.hpp
//  testSFML
//
//  Created by Nick Beckley on 9/22/20.
//

#ifndef terrain_hpp
#define terrain_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "game.hpp"


class Terrain{
public:
    Terrain();
    sf::VertexArray get_terrain_points();
    sf::Sprite sprite;
    sf::VertexArray terrainPoints;
    
    float getY(float x);
    
private:
    
};


#endif /* terrain_hpp */
