//
//  lander.hpp

#ifndef lander_hpp
#define lander_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

class Lander {
public:
    Lander();
    sf::Vector2f pos;
    float h_vel;
    float v_vel;
    int altitude;
    int fuel;
    sf::Sprite sprite;
    sf::Texture texture;
    
    sf::Vector2f getPos(Lander lander);
};

sf::Sprite make_sprite();

#endif /* lander_hpp */
