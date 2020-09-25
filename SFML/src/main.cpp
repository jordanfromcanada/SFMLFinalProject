// Lunar Lander game
// Final Project for C++, by Nick Beckley and Jordan Becker

/**
Machine settings:
 - in XCode > File > Project Settings > Advanced choose 'Custom'
 and set the 'Absolute' path to /.../SFMLFinalProject/SFML
 - in Xcode > Product > Scheme > Edit Scheme
    - under 'Run' and 'Diagnostics', turn on the Address Sanitizer;
    - under 'Run' and 'Options', use a custom working directory of /.../SFMLFinalProject/SFML/src
 */

#include "game.hpp"

using std::cout;
using std::endl;

/*
 // TODO::
 - improve collision detection
 - make terrain have slopes rather than jagged edges
 - freeze screen when lander is properly landed and display score in flashing green text
 - flash yellow upon crash
 */


int main()
{
    sf::Music theme_music;
    if (!theme_music.openFromFile("../src/MainMusic.ogg")){ return -1; } // couldn't load theme_music file
    theme_music.play(); // play theme music
    
    Game game; // create game instance, calling default constructor
    game.Run(); // open a window running the game
    
    return 0;
}
