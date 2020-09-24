//
//  game.cpp
//  testSFML
//
//  Created by Nick Beckley on 9/22/20.
//

#include "game.hpp"
#include <chrono>
#include <ctime>
using std::cout;
using std::endl;

//sets frame limit to 60fps
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game():
// makes a window that can only be closed and has a title bar; no resizing is allowed
window(sf::VideoMode(1200, 1200), "Lunar Lander", sf::Style::Close | sf::Style::Titlebar)
{
    window.setFramerateLimit(60);
    Terrain terrain; // new terrain object
    terrain_points = terrain.get_terrain_points();
    Lander lander; // new lander object
    fuel_rem = lander.fuel;
    altitude = lander.altitude;
    hVelocity = lander.h_vel;
    vVelocity = lander.v_vel;
}

void Game::Run(){
    
    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();
    cout << "Vertex count: " << terrain_points.getVertexCount() << endl;
     
    for (int i = 0; i < terrain_points.getVertexCount(); i++)
    {
        cout << "x: " << terrain_points[i].position.x << " y: " << terrain_points[i].position.y << endl;
    }

    while (window.isOpen()) {
        
        //clock_t begin = clock();
        sf::Vector2f pos_beg = lander.sprite.getPosition();
        
        // starts the clock
        sf::Time elapsed = clock.getElapsedTime();

        txt[1].val = elapsed.asSeconds();// update time
        window.draw(terrain_points);
        drawTxt();
        window.display();
        processEvents();
        
        sf::Vector2f pos_end = lander.sprite.getPosition();
        //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        txt[4].val = (pos_end.x - pos_beg.x)/TimePerFrame.asSeconds();
        txt[5].val = (pos_end.y - pos_beg.y)/TimePerFrame.asSeconds();
        txt[3].val = 1200-(lander.sprite.getPosition().y);
        
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
    
    sf::FloatRect collisionBox =  lander.sprite.getGlobalBounds();
    int lander_bottom_Y = collisionBox.top + collisionBox.height;
    int lander_left_X = collisionBox.left;
    int lander_right_X = collisionBox.left + collisionBox.width;
    
    if (terrain_points[lander_left_X].position.y <= lander_bottom_Y
        || terrain_points[lander_right_X].position.y <= lander_bottom_Y)
    {
        cout << "Collision at x: " << terrain_points[lander_left_X].position.x
        << " y: " << terrain_points[lander_left_X].position.y << endl;
    }
    
//    cout << "terrain height at lander left: " << terrain_points[lander_left_X].position.y << endl;
//    cout << "terrain height at lander right: " << terrain_points[lander_right_X].position.y << endl;
    
    
    clock_t begin = clock();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    
    sf::Vector2f pos1 = lander.sprite.getPosition();
    float offset_X = lander.h_vel * 0.0167;
    float offset_Y = lander.v_vel * 0.0167;
    lander.sprite.setPosition(pos1.x + offset_X, pos1.y + offset_Y);
    
    
    sf::Vector2f pos = lander.sprite.getPosition();
    float offsetX = 0;
    float offsetY = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        offsetX = -5.0f;
        offsetY = 0.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        offsetX = 5.0f;
        offsetY = 0.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        offsetX = 0.0f;
        offsetY = -5.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        offsetX = 0.0f;
        offsetY = 5.0f;
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

//bool Game::pointCollision(sf::FloatRect rect, sf::Vector2f point){
//    if (rect.contains(point)) {
//        return true;
//    }
//    return false;
//}

bool Game::checkCollision(sf::FloatRect rect, sf::Vector2f a_p1, sf::Vector2f a_p2){
    // Find min and max X for the segment
     auto minX = std::min(a_p1.x, a_p2.x);
     auto maxX = std::max(a_p1.x, a_p2.x);

     // Find the intersection of the segment's and rectangle's x-projections
     if (maxX > rect.left + rect.width) {
         maxX = rect.left + rect.width;
     }

     if (minX < rect.left) {
         minX = rect.left;
     }

     // If Y-projections do not intersect then there's no intersection
     if (minX > maxX) { return false; }

     // Find corresponding min and max Y for min and max X we found before
     auto minY = a_p1.y;
     auto maxY = a_p2.y;

     auto dx = a_p2.x - a_p1.x;
     if (std::abs(dx) > 0.0000001f) {
         auto k = (a_p2.y - a_p1.y) / dx;
         auto b = a_p1.y - k * a_p1.x;
         minY = k * minX + b;
         maxY = k * maxX + b;
     }

     if (minY > maxY) {
         std::swap(minY, maxY);
     }

     // Find the intersection of the segment's and rectangle's y-projections
     if (maxY > rect.top + rect.height) {
         maxY = rect.top + rect.height;
     }

     if (minY < rect.top) {
         minY = rect.top;
     }

     // If Y-projections do not intersect then there's no intersection
     if (minY > maxY) { return false; }
     return true;
 }

float Game::getY(float x){
    for(int i = 0; i < 1200; i++){
        if(terrain_points[i].position.x == x){
            return terrain_points[i].position.y;
        }
    }
}
