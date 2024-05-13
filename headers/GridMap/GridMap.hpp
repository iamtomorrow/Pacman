#ifndef GRIDMAP_HPP
#define GRIDMAP_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../math/Math.hpp"

class GridMap {
    public:
    unsigned int xDimension;
    unsigned int yDimension;
    int size;
    int cellCollided;
    int pelletCollected;
    
    std::vector< std::vector <int>> grid;
    std::vector< sf::RectangleShape> cells;
    std::vector< sf::CircleShape> pellets;
    std::vector< sf::Vector2f> availablePositions;

    sf::Color ColorAvailable = sf::Color( 0, 0, 1 );
    sf::Color ColorLeft = sf::Color( 0, 0, 255 );               // 1
    sf::Color ColorRight = sf::Color( 0, 0, 254 );              // 2
    sf::Color ColorTop = sf::Color( 0, 0, 253 );                // 3
    sf::Color ColorDown = sf::Color( 0, 0, 252 );               // 4
    sf::Color ColorRightDown = sf::Color( 0, 0, 250 );          // 6
    sf::Color ColorLeftDown = sf::Color( 0, 0, 251 );           // 7
    sf::Color ColorRightTop = sf::Color( 0, 0, 248 );           // 8
    sf::Color ColorLeftTop = sf::Color( 0, 0, 249 );            // 9

    sf::Texture TextureLeftTopCorner = sf::Texture( );          // -1
    sf::Texture TextureRightTopCorner = sf::Texture( );         // -2
    sf::Texture TextureLeftBottomCorner = sf::Texture( );       // -3
    sf::Texture TextureRightBottomCorner = sf::Texture( );      // -4
    sf::Texture TextureLeft = sf::Texture( );                   // 1
    sf::Texture TextureRight = sf::Texture( );                  // 2
    sf::Texture TextureTop = sf::Texture( );                    // 3
    sf::Texture TextureDown = sf::Texture( );                   // 4
    sf::Texture TextureRightDown = sf::Texture( );              // 6
    sf::Texture TextureLeftDown = sf::Texture( );               // 7
    sf::Texture TextureRightTop = sf::Texture( );               // 8
    sf::Texture TextureLeftTop = sf::Texture( );                // 9

    GridMap( int factorScale );
    ~GridMap( );

    void initGrid( );
    void applyTexture( );
    void distribuitePellets( );
    void collectPellets( sf::CircleShape object, int orientation );
    bool detectCollisions( sf::CircleShape object, int orientation );
    void repulseObject( sf::CircleShape object, int orientation );
    void getAvailablePositions();

    protected:
    float pelletRadius = 2.f;
    std::vector< std::vector<int>> gridArray = 
    {
    //  1   2  3  4  5  6  7  8  9 10 11 12  13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
        {-1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -2 },
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {2, 0, 9, 8, 0, 9, 3, 8, 0, 9, 3, 3, 8, 0, 9, 3, 3, 3, 3, 3, 3, 3, 3, 8, 0, 9, 3, 3, 8, 0, 9, 3, 8, 0, 1 },
        {2, 0, 1, 2, 0, 1, 5, 2, 0, 1, 5, 5, 2, 0, 7, 4, 4, 4, 5, 5, 5, 5, 5, 2, 0, 1, 5, 5, 2, 0, 1, 5, 2, 0, 1 },
        {2, 0, 7, 6, 0, 7, 4, 6, 0, 1, 5, 5, 2, 0, 0, 0, 0, 0, 1, 5, 5, 5, 5, 2, 0, 7, 4, 4, 6, 0, 7, 4, 6, 0, 1 },
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 5, 5, 2, 0, 9, 3, 8, 0, 1, 5, 5, 5, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {2, 0, 9, 3, 3, 3, 3, 8, 0, 1, 5, 5, 2, 0, 1, 5, 2, 0, 7, 4, 4, 4, 5, 2, 0, 9, 3, 3, 8, 0, 9, 3, 8, 0, 1 },
        {2, 0, 7, 4, 4, 4, 4, 6, 0, 1, 5, 5, 2, 0, 1, 5, 2, 0, 0, 0, 0, 0, 1, 2, 0, 1, 5, 5, 2, 0, 1, 5, 2, 0, 1 },
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 4, 6, 0, 7, 4, 6, 0, 0, 0, 0, 0, 7, 6, 0, 7, 4, 4, 6, 0, 7, 4, 6, 0, 1 },
        {2, 0, 9, 3, 3, 3, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {2, 0, 1, 5, 5, 5, 5, 2, 0, 9, 3, 3, 8, 0, 9, 8, 0, 9, 3, 3, 8, 0, 9, 3, 3, 3, 3, 3, 8, 0, 9, 3, 8, 0, 1 },
        {2, 0, 1, 5, 5, 5, 5, 2, 0, 1, 5, 5, 2, 0, 1, 2, 0, 1, 5, 5, 2, 0, 1, 5, 5, 5, 5, 5, 2, 0, 1, 5, 2, 0, 1 },
        {2, 0, 7, 4, 4, 4, 4, 6, 0, 7, 4, 4, 6, 0, 7, 6, 0, 7, 4, 4, 6, 0, 7, 4, 4, 4, 4, 4, 6, 0, 7, 4, 6, 0, 1 },
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {-3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, -4 },
    };
    
    std::vector< int> verticalGridArray;
    std::vector< int> horizontalGridArray;
};

#endif
