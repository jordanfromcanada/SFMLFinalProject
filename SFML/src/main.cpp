#include "lander.hpp"

using std::cout;
using std::endl;

int main()
{
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
        // end the current frame
        window.display();
    }
    return 0;
}
