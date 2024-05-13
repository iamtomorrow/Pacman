#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../math/Math.hpp"

class Monster 
{
    public:
    sf::CircleShape player;
    sf::Color monsterColor;
    float xPosition;
    float yPosition;
    bool catched;
    float distance;
    float deltaY;
    float deltaX;

    // for vertex data
    float XCoordinate;
    float YCoordinate;
    int currentOrientation;

    Monster( sf::Color monsterColor, float xPosition, float yPosition, float x = 2.f, float y = 2.f );
    ~Monster( );

    sf::CircleShape initMonster();
    void moveMonster( int orientation );
    void calculateDistanceFromPacman( sf::CircleShape pacman );
    void getPossibleOrientations( sf::CircleShape pacman, int orientation );
    void moveByDelta( );
    void moveByAngle( );
    void moveRandom( );

    protected:
    const float monsterRadius = 10.f;
    float x;
    float y;
    std::vector< int> orientationsArray;
    std::vector< int> orientations = { 1, 2, 3 , 4 };
    std::vector< float> dS;
    float minD;

    sf::Texture RedTexture;
    sf::Texture GreenTexture;
    sf::Texture BlueTexture;
    sf::Texture VioletTexture;

    Math math;
};

#endif
