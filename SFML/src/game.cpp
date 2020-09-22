//
//  game.cpp
//  testSFML
//
//  Created by Nick Beckley on 9/22/20.
//

#include "game.hpp"

//sets frame limit to 60fps
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game():
window(sf::VideoMode(1200, 1200), "Lunar Lander")
{
    Terrain terrain; // new terrain object
    terrain_points = terrain.get_terrain_points();
    Lander lander; // new lander object
}

void Game::Run(){
    
    //create clock object when game is ran
    sf::Clock clock;
    // gives us a delta since last update
    sf::Time timeDelta = sf::Time::Zero;
    
    //TODO: move to own class
    //sets the game variables including font and score
    font.loadFromFile("ARI.ttf");
    score.setString("score: ");
    score.setFont(font);
    score.setCharacterSize(30);
    score.setFillColor(sf::Color::White);
    score.setPosition(30, 30);
    
    //TODO:: move these to their own class
    //assign texture to game variables
    texture.loadFromFile("lunar_lander3.png"); // load lander image
    sprite.setColor(sf::Color::Red); // set lander color
    sprite.setScale(0.1f, 0.1f); // 10% scale
    sprite.setTexture(texture); // sprite is now lander image
    sprite.setPosition(100, 100); // sets it towards top of screen
    
    while (window.isOpen())
    {
        timeDelta += clock.restart(); //updates the timeSinceLastUpdate (time delta)
        while (timeDelta > TimePerFrame) // updates the screen if timeDetla exceeds timeperframe
        {
            timeDelta -= TimePerFrame;
            processEvents();
            update(TimePerFrame); // redraw moved stuff
        }
        render(); // draws the things
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    //TODO: add logic for what happens when a player presses a key.
    
}

//called every time the game is updated ~60 times a second
void Game::processEvents(){
    
    sf::Event event{};
    
       while (window.pollEvent(event))
       {
           switch (event.type)
           {
               case sf::Event::KeyPressed:
                   handlePlayerInput(event.key.code, true);
                   break;
               case sf::Event::KeyReleased:
                   handlePlayerInput(event.key.code, false);
                   break;
               case sf::Event::Closed:
                   window.close();
                   break;
               default:
                   break;
           }
       }
}

void Game::update(sf::Time deltaTime){
    
    //TODO: redraw lander here as it moves
    
}

//renders everything
void Game::render(){
    window.clear(sf::Color(0, 0, 0, 255));
    
    window.draw(sprite);
    
    window.draw(terrain_points);
    
    window.draw(score);
    
    //TODO: add other text objects to be displayed
    
    window.display();
    
}




