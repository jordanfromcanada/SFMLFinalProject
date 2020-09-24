//
//  lander.cpp

#include "lander.hpp"

Lander::Lander(){
    sf::Vector2f defaultPos = {600,50};
    texture.loadFromFile("../src/lunar_lander3.png"); // load lander image
    sprite.setColor(sf::Color::Red); // set lander color
    sprite.setScale(0.1f, 0.1f); // 10% scale
    sprite.setTexture(texture); // sprite is now lander image
    sprite.setPosition(defaultPos); // sets it towards top of screen
    h_vel = 0.0;
    v_vel = 40.0;
    pos = defaultPos;
    fuel = 1000;
    altitude = 1000;

}

sf::Vector2f getPos(Lander lander){
    sf::Vector2f pos = lander.sprite.getPosition();
    return pos;
};

