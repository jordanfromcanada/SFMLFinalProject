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
    sf::Text score;
    sf::Font font;
    
    
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    
};


#endif /* game_hpp */
