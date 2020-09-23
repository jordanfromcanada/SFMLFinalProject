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
#include "terrain.hpp"
#include "lander.hpp"

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
    
    void drawText();
    void drawTxt(); // Jordan's testing
    
    Lander lander;
    
    
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    
};

struct text_pos
{
    std::string name;
    float val;
    int x;
    int y;
};


#endif /* game_hpp */
