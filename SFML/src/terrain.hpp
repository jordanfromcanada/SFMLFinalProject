//
//  terrain.hpp

#ifndef terrain_hpp
#define terrain_hpp

#include "game.hpp"

class Terrain{
    
public:
    Terrain();
    sf::VertexArray get_terrain_points();
    sf::Sprite sprite;
    sf::VertexArray terrainPoints;
};

#endif /* terrain_hpp */
