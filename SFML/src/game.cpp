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

    
    //TODO:: move these to their own class
    //assign texture to game variables
//    texture.loadFromFile("lunar_lander3.png"); // load lander image
//    sprite.setColor(sf::Color::Red); // set lander color
//    sprite.setScale(0.1f, 0.1f); // 10% scale
//    sprite.setTexture(texture); // sprite is now lander image
//    sprite.setPosition(100, 100); // sets it towards top of screen
    
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
    
    window.draw(lander.sprite);
    
    window.draw(terrain_points);
    
    drawText();
    
    //TODO: add other text objects to be displayed
    
    window.display();
    
}

void Game::drawText(){
    sf::Font font;
    font.loadFromFile("ARI.ttf");
    sf::Text score("Score: ", font);
    score.setCharacterSize(30);
    score.setFillColor(sf::Color::White);
    score.setPosition(30, 30);
    window.draw(score);
    sf::Text scoreLabel("0", font);
    scoreLabel.setCharacterSize(30);
    scoreLabel.setFillColor(sf::Color::White);
    scoreLabel.setPosition(125, 30);
    window.draw(scoreLabel);
    sf::Text fuel("Fuel: ", font);
    fuel.setCharacterSize(30);
    fuel.setFillColor(sf::Color::White);
    fuel.setPosition(30, 90);
    window.draw(fuel);
    sf::Text fuelLabel("0", font);
    fuelLabel.setCharacterSize(30);
    fuelLabel.setFillColor(sf::Color::White);
    fuelLabel.setPosition(115, 90);
    window.draw(fuelLabel);
    sf::Text altitude("Altitude: ", font);
    altitude.setCharacterSize(30);
    altitude.setFillColor(sf::Color::White);
    altitude.setPosition(30, 150);
    window.draw(altitude);
    sf::Text altitudeLabel("0", font);
    altitudeLabel.setCharacterSize(30);
    altitudeLabel.setFillColor(sf::Color::White);
    altitudeLabel.setPosition(150, 150);
    window.draw(altitudeLabel);
    
    sf::Text hvelocity("Horizontal Velocity: ", font);
    hvelocity.setCharacterSize(30);
    hvelocity.setFillColor(sf::Color::White);
    hvelocity.setPosition(800, 30);
    window.draw(hvelocity);
    sf::Text hvelocityLabel("0", font);
    hvelocityLabel.setCharacterSize(30);
    hvelocityLabel.setFillColor(sf::Color::White);
    hvelocityLabel.setPosition(1070, 30);
    window.draw(hvelocityLabel);
    
    sf::Text vvelocity("Vertical Velocity: ", font);
    vvelocity.setCharacterSize(30);
    vvelocity.setFillColor(sf::Color::White);
    vvelocity.setPosition(800, 90);
    window.draw(vvelocity);
    sf::Text vvelocityLabel("0", font);
    vvelocityLabel.setCharacterSize(30);
    vvelocityLabel.setFillColor(sf::Color::White);
    vvelocityLabel.setPosition(1030, 90);
    window.draw(vvelocityLabel);
    
}




