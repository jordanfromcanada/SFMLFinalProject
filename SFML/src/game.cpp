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
// makes a window that can only be closed and has a title bar; no resizing is allowed
window(sf::VideoMode(1200, 1200), "Lunar Lander", sf::Style::Close | sf::Style::Titlebar)
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
    
    sf::Clock clock; // starts the clock
    sf::Time elapsed1 = clock.getElapsedTime();
    
    while (window.isOpen()) {
        sf::Time elapsed = clock.getElapsedTime();
        txt[1].val = elapsed.asSeconds(); // update time
        window.draw(terrain_points);
        drawTxt();
        window.display();
        processEvents();
    }
}

//called every time the game is updated ~60 times a second
void Game::processEvents(){
    sf::Event event;
       while (window.pollEvent(event))
       {
           switch (event.type) {
               case sf::Event::Closed: {
                  window.close();
                  break; }}
       }
    
    sf::Vector2f pos = lander.sprite.getPosition();
    float offsetX = 0;
    float offsetY = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        offsetX = -1.0f;
        offsetY = 0.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        offsetX = 1.0f;
        offsetY = 0.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        offsetX = 0.0f;
        offsetY = -1.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        offsetX = 0.0f;
        offsetY = 1.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    window.clear();
    window.draw(lander.sprite);
}

// create a vector of text to be displayed, then display it
// to update e.g. score, use: txt.val
void Game::drawTxt() {
    sf::Font font;
    font.loadFromFile("../src/ARI.ttf");
    
    // loop over vec and display the text
    for (int i = 0; i < txt.size(); i++)
    {
        sf::Text text(txt[i].name + " : "
                    + std::to_string(txt[i].val), font);
        text.setPosition(txt[i].x, txt[i].y);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(30);
        window.draw(text);
    }
}



