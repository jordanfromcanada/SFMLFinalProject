/* retrieved and modified:
 https://github.com/SonarSystems/SFML-2.1-Tutorial-51---Menu-Class/tree/master/TutorialSFML/TutorialSFML
 */

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define MAX_NUMBER_OF_ITEMS 3


class Menu {
    
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
    sf::Font font;

private:
	int selectedItemIndex;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

