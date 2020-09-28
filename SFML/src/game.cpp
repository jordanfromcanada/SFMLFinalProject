//
//  game.cpp

#include "game.hpp"
#include "Menu.h"

using std::cout;
using std::endl;

//sets frame limit to 60fps
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
// create a window that can't be resized, set to 1200x1200 pixels
sf::RenderWindow window(sf::VideoMode(1200, 1200), "Lunar Lander", sf::Style::Close | sf::Style::Titlebar);
// create a menu object used to display menu options and background image
Menu menu(window.getSize().x, window.getSize().y);

Game::Game() { // default constructor
    window.setFramerateLimit(60); // set framerate to 60fps
    font.loadFromFile("../src/ARI.ttf"); // set font to Arial
    Terrain terrain; // new terrain object
    terrain_points = terrain.get_terrain_points(); // assign vector of points constituting the landing surface
    Lander lander; // new lander object
    fuel_rem = lander.fuel; // fuel remaining
    altitude = lander.altitude; // current altitude
    hVelocity = lander.h_vel; // current horizontal velocity
    vVelocity = lander.v_vel; // current vertical velocity
    play = false; } // when true, menu screen is exited and gameplay begins

// runs menu screen
void Game::Run(){
    
    // sf::Clock clock; // track time elapsed
    
    while (window.isOpen())
    { menu_screen_event_handler(); }} // handle user input for menu screen selection

// handle user input for menu screen selection
void Game::menu_screen_event_handler() {
    
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break; }
            default: break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Up: { menu.MoveUp(); break; }
                    case sf::Keyboard::Down: { menu.MoveDown(); break; }
                    case sf::Keyboard::Return: {
                    
                        switch (menu.GetPressedItem()) {
                            case 0: { play = true;
                                clock.restart(); // begin counting time once game begins (now)
                                break; }// play button pressed
                            case 1: { break; } // option button pressed
                            case 2: { window.close(); break; }}// exit button pressed
                    
                    } break; default: break; } break; } }
    
    // play button was not selected
    if (play == false)
    { menu.draw(window); window.display(); }
    else
    // play button was selected, launch game
    { launchGame(); }}

// display text, control lander position, and re-draw each frame
void Game::launchGame(){

    txt[1].val = get_time_elapsed(); // display time elapsed
    txt[2].val = fuel_rem;           // display fuel remaining
    txt[3].val = get_altitude();     // display altitude relative to terrain
    txt[4].val = get_h_veocity();    // display horizontal velocity
    txt[5].val = get_v_veocity();    // display vertical velocity
    
    check_for_landing(); // check if the lander is in a viable landing spot
    reposition_lander(); // adjusts lander position each frame for horizontal velocity and vertical velocity
    game_screen_user_input_handler(); // update lander position for user key presses W,A,S,D
    
    window.clear(); // clear screen to black
    window.draw(lander.sprite); // display lander after positional updates
    window.draw(terrain_points); // dispaly terrain (only needs to be done once)
    draw_onscreen_text(); // display time, score, fuel, horiz veloc, vert veloc, altitude
    window.display(); }

// Check for collisions between lander and terrain
bool Game::checkCollision(sf::FloatRect rect, sf::Vector2f a_p1, sf::Vector2f a_p2){
    
    // Find min and max X for the segment
     auto minX = std::min(a_p1.x, a_p2.x);
     auto maxX = std::max(a_p1.x, a_p2.x);

     // Find the intersection of the segment's and rectangle's x-projections
     if (maxX > rect.left + rect.width) {
         maxX = rect.left + rect.width; }

     if (minX < rect.left) {
         minX = rect.left; }

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
         maxY = k * maxX + b; }

     if (minY > maxY) {
         std::swap(minY, maxY); }

     // Find the intersection of the segment's and rectangle's y-projections
     if (maxY > rect.top + rect.height) {
         maxY = rect.top + rect.height; }

     if (minY < rect.top) {
         minY = rect.top; }

     // If Y-projections do not intersect then there's no intersection
     if (minY > maxY) { return false; }
     return true; }

// return time elapsed since user selected 'Play' on menu
float Game::get_time_elapsed() {
    
    sf::Time elapsed = clock.getElapsedTime();
    return elapsed.asSeconds(); } // update time elapsed for displaying on-screen

// return lander horizontal velocity in pixels per second
float Game::get_h_veocity() {
    
    sf::Vector2f pos_beg = lander.sprite.getPosition();
    sf::Vector2f pos_end = lander.sprite.getPosition();
    float h_vel = (pos_end.x - pos_beg.x)/TimePerFrame.asSeconds();
    return h_vel; }
    
// return lander vertical velocity in pixels per second
float Game::get_v_veocity() {
    
    sf::Vector2f pos_beg = lander.sprite.getPosition();
    sf::Vector2f pos_end = lander.sprite.getPosition();
    float v_vel = (pos_end.y - pos_beg.y)/TimePerFrame.asSeconds();
    return v_vel; }

// check if lander is on the ground
void Game::check_for_landing() {
    
    sf::FloatRect collisionBox =  lander.sprite.getGlobalBounds();
    float lander_bottom_Y = collisionBox.top + collisionBox.height;
    float lander_left_X = collisionBox.left;
    float lander_right_X = collisionBox.left + collisionBox.width;

    /* a point at the bottom left or right of the lander must be
    <= to the corresponding terrain point directly below it */
    if (terrain_points[lander_left_X].position.y <= lander_bottom_Y
        || terrain_points[lander_right_X].position.y <= lander_bottom_Y) {
            int timesec = clock.getElapsedTime().asSeconds();
            lander.onGround();
        txt[0].val += 1; }} // increment score

// adjusts lander position each frame for horizontal velocity and vertical velocity
void Game::reposition_lander() {
    
    sf::Vector2f pos1 = lander.sprite.getPosition();
    float offset_X = lander.h_vel * TimePerFrame.asSeconds();
    float offset_Y = lander.v_vel * TimePerFrame.asSeconds();
    lander.sprite.setPosition(pos1.x + offset_X, pos1.y + offset_Y); }

// return current altitude based on the y-coordinate at the bottom of the lander
float Game::get_altitude() {
    
    sf::FloatRect collisionBox =  lander.sprite.getGlobalBounds();
    int lander_bottom_coord = collisionBox.top + collisionBox.height;
    return getY(lander_bottom_coord) - lander_bottom_coord; }

// update lander position based on W, A, S, D user input
void Game::game_screen_user_input_handler() {
    
    sf::Vector2f pos = lander.sprite.getPosition();
    float offsetX = 0;
    float offsetY = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        if(fuel_rem > 0){
        offsetX = -5.0f;
        offsetY = 0.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
        fuel_rem -= 2;
        }}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        if(fuel_rem > 0){
        offsetX = 5.0f;
        offsetY = 0.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
        fuel_rem -= 2;
        }}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        if(fuel_rem > 0){
        offsetX = 0.0f;
        offsetY = -5.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
        fuel_rem -= 2;
        }}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        if(fuel_rem > 0){
        offsetX = 0.0f;
        offsetY = 5.0f;
        lander.sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
        fuel_rem -= 2;
        }}}

// display text in top portion of screen
void Game::draw_onscreen_text() {
    
    for (int i = 0; i < txt.size(); i++) {
        sf::Text text(txt[i].name + " : " + std::to_string(txt[i].val), menu.font);
        text.setPosition(txt[i].x, txt[i].y);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(30);
        window.draw(text); }}

// retrieve the terrain's y-coordinate corresponding to the lander's x-coordinate above the terrain
float Game::getY(float x){
    
    sf::FloatRect collisionBox =  lander.sprite.getGlobalBounds();
    int lander_bottom_Y1 = collisionBox.top + collisionBox.height;
    for(int i = 0; i < 1200; i++){
        if(terrain_points[i].position.x == x) {
            return terrain_points[i].position.y; }}}


