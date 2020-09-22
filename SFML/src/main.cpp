#include "lander.hpp"

using std::cout;
using std::endl;

int main()
{
    // TODO: put this in Lunar class method & member
    sf::Font font;
    font.loadFromFile("ARI.ttf");
    sf::Text score("score: ", font);
    score.setCharacterSize(30);
    score.setFillColor(sf::Color::White);
    score.setPosition(30, 30);
    //score.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    // TODO: put this in Lunar class method & member
    sf::Texture texture; // create Texture object
    texture.loadFromFile("lunar_lander3.png"); // load lander image
    sf::Sprite sprite; // create Sprite object
    sprite.setColor(sf::Color::Red); // set lander color
    sprite.setScale(0.1f, 0.1f); // 10% scale
    sprite.setTexture(texture); // sprite is now lander image
    sprite.setPosition(600, 600); // position lander (x, y)
    
    // create terrain points
    sf::VertexArray terrain_points = get_terrain_points();
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Asteroids");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered
        // since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color(0, 0, 0, 255));
        //window.clear();
        
        window.draw(sprite);
        
        window.draw(terrain_points);
        
        window.draw(score);
        
        // end the current frame
        window.display();
    }
    return 0;
}
