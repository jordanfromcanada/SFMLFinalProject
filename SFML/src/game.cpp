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
    fuel_rem = lander.fuel;
    altitude = lander.altitude;
    hVelocity = lander.h_vel;
    vVelocity = lander.v_vel;
}

void Game::Run(){
    
    //create clock object when game is ran
    sf::Clock clock;
    // gives us a delta since last update
    sf::Time timeDelta = sf::Time::Zero;
    
    while (window.isOpen())
    {
        //updates the timeSinceLastUpdate (time delta)
        timeDelta += clock.restart();
        // updates the screen if timeDetla exceeds timeperframe
        while (timeDelta > TimePerFrame)
        {
            timeDelta -= TimePerFrame;
            processEvents(); // detect pollEvent e.g. keypress
            update(TimePerFrame); // redraw moved stuff
        }
        render(); // draws the things
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    //TODO: add logic for what happens when a player presses a key.
    
    //Respond to key pressed events
    // setPos(x, y) -> e.g. setPos(-1, 0) is left 1.
    /*
    if (key == sf::Keyboard::Left)
        Lander.sprite.setPos(-1, 0);
    if (key == sf::Keyboard::Right)
        Lander.sprite.setPos(-1, 0);
    if (key == sf::Keyboard::Up)
        Lander.sprite.setPos(-1, 0);
    if (key == sf::Keyboard::Down)
        Lander.sprite.setPos(-1, 0);
    if (key == sf::Keyboard::Enter)
        Lander.sprite.setPos(0, 0);
     */
    
}

//called every time the game is updated ~60 times a second
void Game::processEvents(){
    
    sf::Event event{};
    
       while (window.pollEvent(event))
       {
           switch (event.type)
           {
               case sf::Event::KeyPressed: {
                   handlePlayerInput(event.key.code, true);
                   break; }
               case sf::Event::KeyReleased: {
                   handlePlayerInput(event.key.code, false);
                   break; }
               case sf::Event::Closed: {
                   window.close();
                   break; }
               default:
                   break;
           }
       }
}

void Game::update(sf::Time deltaTime){
    
    //TODO: redraw lander here as it moves
    
    sf::Vector2f pos = lander.sprite.getPosition();
    float offsetX = 1;
    float offsetY = 1;
    lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    
}

//renders everything
void Game::render(){
    window.clear(sf::Color(0, 0, 0, 255));

    window.draw(lander.sprite);
    
    window.draw(terrain_points);
    
    //drawText();
    drawTxt();
    
    //TODO: add other text objects to be displayed
    
    window.display();
    
}

// create a vector of text to be displayed, then display it
// to update e.g. score, use: txt.val
void Game::drawTxt()
{   // populate vector of text_pos structs for text to be displayed
    // in the form (string, value, x pos, y pos)
    // TODO: store this vector in a Game member so it can be dynamically changed
    std::vector<text_pos> txt {
        {"Score",            0, 30, 30},
        {"Time",             0, 30, 90},
        {"Fuel",             0, 30, 150},
        {"Altitude",         0, 800, 30},
        {"Horizontal Speed", 0, 800, 90},
        {"Vertical Speed",   0, 800, 150},
    };
    
    sf::Font font;
    font.loadFromFile("ARI.ttf");
    
    // loop over vec and display the text
    for (int i = 0; i < txt.size(); i++)
    {
        sf::Text text(txt[i].name + " : "
                    + std::to_string(txt[i].val), font);
        text.setPosition(txt[i].x, txt[i].y);
        text.setFillColor(sf::Color::Blue);
        text.setCharacterSize(30);
        window.draw(text);
    }
}


void Game::drawText(){
    sf::Font font;
    font.loadFromFile("ARI.ttf");
    sf::Text scoreText("Score: ", font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(30, 30);
    window.draw(scoreText);
    sf::Text scoreLabel(std::to_string(score), font);
    scoreLabel.setCharacterSize(30);
    scoreLabel.setFillColor(sf::Color::White);
    scoreLabel.setPosition(125, 30);
    window.draw(scoreLabel);
    sf::Text fuel("Fuel: ", font);
    fuel.setCharacterSize(30);
    fuel.setFillColor(sf::Color::White);
    fuel.setPosition(30, 90);
    window.draw(fuel);
    sf::Text fuelLabel(std::to_string(fuel_rem), font);
    fuelLabel.setCharacterSize(30);
    fuelLabel.setFillColor(sf::Color::White);
    fuelLabel.setPosition(115, 90);
    window.draw(fuelLabel);
    sf::Text altitudeText("Altitude: ", font);
    altitudeText.setCharacterSize(30);
    altitudeText.setFillColor(sf::Color::White);
    altitudeText.setPosition(30, 150);
    window.draw(altitudeText);
    sf::Text altitudeLabel(std::to_string(altitude), font);
    altitudeLabel.setCharacterSize(30);
    altitudeLabel.setFillColor(sf::Color::White);
    altitudeLabel.setPosition(150, 150);
    window.draw(altitudeLabel);
    
    sf::Text hVelocityText("Horizontal Velocity: ", font);
    hVelocityText.setCharacterSize(30);
    hVelocityText.setFillColor(sf::Color::White);
    hVelocityText.setPosition(800, 30);
    window.draw(hVelocityText);
    sf::Text hvelocityLabel(std::to_string(hVelocity), font);
    hvelocityLabel.setCharacterSize(30);
    hvelocityLabel.setFillColor(sf::Color::White);
    hvelocityLabel.setPosition(1070, 30);
    window.draw(hvelocityLabel);
    
    sf::Text vVelocityText("Vertical Velocity: ", font);
    vVelocityText.setCharacterSize(30);
    vVelocityText.setFillColor(sf::Color::White);
    vVelocityText.setPosition(800, 90);
    window.draw(vVelocityText);
    sf::Text vvelocityLabel(std::to_string(vVelocity), font);
    vvelocityLabel.setCharacterSize(30);
    vvelocityLabel.setFillColor(sf::Color::White);
    vvelocityLabel.setPosition(1030, 90);
    window.draw(vvelocityLabel);
    
}




