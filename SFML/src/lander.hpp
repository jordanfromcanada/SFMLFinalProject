//
//  lander.hpp

#ifndef lander_hpp
#define lander_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

class Lander {
public:
    // TODO: set sprite texture, position, color in class constructor
    // Lander::Lander();
    
    float h_vel;
    float v_velocity;
    float altitude;
    float fuel;
    
private:
};

sf::VertexArray get_terrain_points();
sf::Sprite make_sprite();

#endif /* lander_hpp */