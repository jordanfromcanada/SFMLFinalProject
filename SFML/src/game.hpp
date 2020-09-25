//
//  game.hpp
//  testSFML

#ifndef game_hpp
#define game_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream> // to display text_pos.val with 2 decimal places
#include <iomanip> // std::setprecision
#include <chrono>
#include <ctime>
#include "terrain.hpp"
#include "lander.hpp"

// struct to store text members that are display on-screen, e.g. time, altitude, vertical velocity...
struct text_pos {
    
    std::string name;
    float val;
    int x;
    int y; };

class Game {
    
public:
    Game();
    void Run();
    static const sf::Time TimePerFrame;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::VertexArray terrain_points;
    std::vector<sf::Text> myText;
    int score;
    bool play;
    int fuel_rem;
    int altitude;
    float hVelocity;
    float vVelocity;
    sf::Font font; // initialized to "../src/ARI.ttf" in constructor
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
        {"Vertical Speed",   0, 800, 150} };
    
    bool checkCollision(sf::FloatRect rect, sf::Vector2f a_p1, sf::Vector2f a_p2);
    bool pointCollision(sf::FloatRect rect, sf::Vector2f point);
    void menu_screen_event_handler();
    float get_time_elapsed();
    float get_h_veocity();
    float get_v_veocity();
    void check_for_landing();
    void reposition_lander();
    float get_altitude();
    void game_screen_user_input_handler();
    void draw_onscreen_text();
    float getY(float x);
    
private:
    void launchGame();
    void update(sf::Time deltaTime);
};

#endif /* game_hpp */
