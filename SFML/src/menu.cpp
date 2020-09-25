/* Retrieved and modified:
 https://github.com/SonarSystems/SFML-2.1-Tutorial-51---Menu-Class/tree/master/TutorialSFML/TutorialSFML
 */

#include "menu.h"
#include <SFML/Audio.hpp>

// Menu constructor - creates inital selection screen buttons 'Play', 'Options', and 'Exit'
Menu::Menu(float width, float height) {
    
    font.loadFromFile("../src/ARI.ttf"); // Arial font
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red); // Play button is red when selected
	menu[0].setString("Play");
    menu[0].setCharacterSize(100);
	menu[0].setPosition(sf::Vector2f(width / 12, 50));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 12, 200));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 12, 250));
    
	selectedItemIndex = 0; }

// Destructor
Menu::~Menu() {}

// draw background
void Menu::draw(sf::RenderWindow &window) {
    
    sf::Texture t;
    t.loadFromFile("../src/bg.jpg"); // menu screen lunar lander image background
    sf::Sprite s(t);
    window.draw(s);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    { window.draw(menu[i]);} }

// arrow key selection is moved up, text highlighting changes
void Menu::MoveUp() {
    
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red); }}

// arrow key selection is moved down, text highlighting changes
void Menu::MoveDown() {
    
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red); }}
