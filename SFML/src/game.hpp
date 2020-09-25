//
//  game.hpp
//  testSFML
//
//  Created by Nick Beckley on 9/22/20.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // to display text_pos.val with 2 decimal places
#include <iomanip> // std::setprecision
#include "terrain.hpp"
#include "lander.hpp"


struct text_pos
{
    std::string name;
    float val;
    int x;
    int y;
};

class Game {
public:
    Game();
    void Run();
    
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::VertexArray terrain_points;
    std::vector<sf::Text> myText;
    int score;
    int fuel_rem;
    int altitude;
    float hVelocity;
    float vVelocity;
    void drawTxt();
    Lander lander;
    sf::Time scoreTime;
    sf::Clock clock;
    /* populate vector of text_pos structs for text to be displayed
    in the form (string, value, x pos, y pos) */
    std::vector<text_pos> txt {
        {"Score",            0, 30, 30},
        {"Time",             0, 30, 90},
        {"Fuel",             0, 30, 150},
        {"Altitude",         0, 800, 30},
        {"Horizontal Speed", 0, 800, 90},
        {"Vertical Speed",   0, 800, 150},
    };
    
    bool checkCollision(sf::FloatRect rect, sf::Vector2f a_p1, sf::Vector2f a_p2);
    
    bool pointCollision(sf::FloatRect rect, sf::Vector2f point);
  
    float getY(float x);

private:
    void processEvents();
    void update(sf::Time deltaTime);
};

#endif /* game_hpp */
