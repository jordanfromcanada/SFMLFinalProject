//
//  lander.cpp

#include "lander.hpp"

// Lander default constructor
Lander::Lander(){
    
    sf::Vector2f defaultPos = {600,50}; // default position at x=600, y=50
    texture.loadFromFile("../src/lunar_lander3.png"); // load lander image
    sprite.setColor(sf::Color::Red); // set lander color
    sprite.setScale(0.1f, 0.1f); // 10% scale from original lander .png
    sprite.setTexture(texture); // sprite is now lander image
    sprite.setPosition(defaultPos); // sets it towards top of screen
    h_vel = 10.0; // horizontal velocity default
    v_vel = 80.0; // vertical velocity default
    pos = defaultPos;
    fuel = 1000; // default starting fuel
    altitude = 1150; } // beginning altitude

// return the lander's current position (center of the sprite) in (x, y) format
sf::Vector2f getPos(Lander lander){
    sf::Vector2f pos = lander.sprite.getPosition();
    return pos;
};

// once landed, set velocities to 0
void Lander::onGround(){
    sprite.setPosition(sprite.getPosition());
    h_vel=0;
    v_vel=0;
}

