#ifndef MATH_HPP
#define MATH_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Math {
    public:

    Math( );
    ~Math( );

    float d( sf::Vector2f a1, sf::Vector2f a2 );
    float d1( sf::Vector2f a1, sf::Vector2f a2, float hx = 2.0 );
    float d2( sf::Vector2f a1, sf::Vector2f a2, float hx = 2.0 );
    float d3( sf::Vector2f a1, sf::Vector2f a2, float hy = 2.0 );
    float d4( sf::Vector2f a1, sf::Vector2f a2, float hy = 2.0 );
    float deltaX( sf::Vector2f a1, sf::Vector2f a2 );
    float deltaY( sf::Vector2f a1, sf::Vector2f a2 );
    float angle( sf::Vector2f a1, sf::Vector2f a2 );
    bool diff1( sf::Vector2f a1, sf::Vector2f a2, float width, float heigth, float radius );
    bool diff2( sf::Vector2f a1, sf::Vector2f a2, float width, float heigth, float radius );
    bool diff3( sf::Vector2f a1, sf::Vector2f a2, float width, float heigth, float radius );
    bool diff4( sf::Vector2f a1, sf::Vector2f a2, float width, float heigth, float radius );

    protected:
    float _deltaX;
    float _deltaY;
    float _d;
};

#endif
