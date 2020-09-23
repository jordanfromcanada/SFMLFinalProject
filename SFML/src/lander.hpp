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
    Lander();
    
    sf::Vector2f pos;
    float h_vel;
    float v_velocity;
    float altitude;
    float fuel;
    sf::Sprite sprite;
    sf::Texture texture;
    
private:

};

sf::Sprite make_sprite();

#endif /* lander_hpp */
